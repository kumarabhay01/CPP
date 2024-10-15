#include<iostream>
#include<thread>
#include<vector>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<functional>
#include<future>


using namespace std;

int func(int a){
	this_thread::sleep_for(chrono::seconds(2));
	cout << "This is the time taking function" << endl;
	return a * a;
}

class ThreadPool {
private:
	int m_threads;
	vector<thread> mv_threads;
	queue<function<void()>> m_tasks;
	mutex mtx;
	condition_variable m_cv;
	bool stop;

public:
	explicit ThreadPool(int numThreads) :m_threads(numThreads),stop(false) {
		for (int i = 0; i < m_threads; i++) {
			mv_threads.emplace_back([this] {
				function<void()> task;
				while (1) {
					unique_lock<mutex> lock(mtx);
					m_cv.wait(lock, [this] {
						return !m_tasks.empty() || stop;
					});

					if (stop)
						return;

					task = move(m_tasks.front());
					m_tasks.pop();
					cout << "Size of Queue : " << m_tasks.size() << endl;
					lock.unlock();

					task();
				}
			});
		}
	}

	~ThreadPool() {
		unique_lock<mutex> lock(mtx);
		stop = true;
		lock.unlock();
		m_cv.notify_all();

		for (auto& th : mv_threads) {
			th.join();
		}
	}

	template<class F,class... Args>
	auto executeTask(F&& f, Args&&... args) -> future<decltype(f(args...))> {

		using return_type = decltype(f(args...));
		auto  task = make_shared<packaged_task<return_type()>>(bind(forward<F>(f), forward<Args...>(args...)));
		future<return_type> res = task->get_future();

		unique_lock<mutex> lock(mtx);
		//m_tasks.push(func);
		m_tasks.emplace([task]()->void {
			(*task)();
		});
		lock.unlock();
		m_cv.notify_one();
		return res;
	}

};

int main() {
	ThreadPool pool(8);

	future<int> res = pool.executeTask(func, 2);
	cout << "Result is : " << res.get() << endl;

	while (1) {
		//pool.executeTask(func);
	}
	return 0;
}
