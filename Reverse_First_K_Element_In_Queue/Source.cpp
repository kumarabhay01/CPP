#include <iostream>
#include <queue>
#include <stack>

// Interface for queue operations
class IQueueService {
public:
    virtual void reverseFirstKElements(int k) = 0;
    virtual void displayQueue() = 0;
};

// Concrete implementation of queue operations
class QueueService : public IQueueService {
private:
    std::queue<int> Queue;

public:
    QueueService(std::queue<int> queue) : Queue(queue) {}

    void reverseFirstKElements(int k) override {
        if (Queue.empty()) {
            std::cout << "Queue is empty, please enter a few elements." << std::endl;
            return;
        }

        if (k > Queue.size()) {
            std::cout << "The value of k is greater than the size of the queue." << std::endl;
            return;
        }

        std::stack<int> Stack;

        for (int i = 0; i < k; i++) {
            Stack.push(Queue.front());
            Queue.pop();
        }

        while (!Stack.empty()) {
            Queue.push(Stack.top());
            Stack.pop();
        }

        for (int i = 0; i < Queue.size() - k; i++) {
            Queue.push(Queue.front());
            Queue.pop();
        }
    }

    void displayQueue() override {
        while (!Queue.empty()) {
            std::cout << Queue.front() << " ";
            Queue.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    std::queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    int k = 3; // Number of elements to reverse
    QueueService queueService(queue);
    queueService.reverseFirstKElements(k);
    queueService.displayQueue();

    return 0;
}
