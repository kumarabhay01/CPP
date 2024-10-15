#pragma once
template<typename T>
class SharedPointer {
private:
	T* m_newMem;
	int* m_counter;

	void incrementCounter() {
		if (m_counter)
			(*m_counter)++;
	}

	void decrementCounter() {
		if (m_counter) {
			(*m_counter)--;
			if ((*m_counter) == 0) {
				if (m_newMem) {
					delete m_newMem;
					delete m_counter;
					m_counter = nullptr;
					m_newMem = nullptr;
				}
			}
		}
	}

public:
	SharedPointer(T* ptr = nullptr) :m_newMem(ptr), m_counter(new int(1)) {
		std::cout << "Shared Pointer Ctor was called\n";
	}

	SharedPointer<T>(const SharedPointer<T>& ptr) {
		m_newMem = ptr.m_newMem;
		m_counter = ptr.m_counter;
		incrementCounter();
	}

	SharedPointer<T>(SharedPointer<T>&& ptr) noexcept {
		m_newMem = ptr.m_newMem;
		m_counter = ptr.m_counter;
		ptr.m_counter = nullptr;
		ptr.m_newMem = nullptr;
	}

	SharedPointer<T>& operator=(const SharedPointer<T>& ptr) {
		if (this != &ptr) {
			decrementCounter();
			m_newMem = ptr.m_newMem;
			m_counter = ptr.m_counter;
			incrementCounter();
		}
		return *this;
	}

	SharedPointer<T>& operator=(SharedPointer<T>&& ptr) noexcept {
		if (this != &ptr) {
			decrementCounter();
			m_newMem = ptr.m_newMem;
			m_counter = ptr.m_counter;
			incrementCounter();
			ptr.m_counter = nullptr;
			ptr.m_newMem = nullptr;
		}
		return *this;
	}

	void reset(T* ptr) {
		decrementCounter();
		m_newMem = ptr;
		m_counter = new int(1);
	}

	void reset() {
		decrementCounter();
		m_newMem = nullptr;
		m_counter = nullptr;
	}

	int getCount() {
		if (m_counter)
			return(*m_counter);

		return -1;
	}

	T* operator->() {
		return m_newMem;
	}

	T& operator*() {
		return(*m_newMem);
	}

	T* get() {
		return m_newMem;
	}
	~SharedPointer() {
		decrementCounter();
	}
};