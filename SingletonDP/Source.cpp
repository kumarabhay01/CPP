#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <string>
#include <sstream>

// Thread-safe Singleton Logger Class
class Logger {
private:
    static Logger* instance;
    static std::mutex mutex;

protected:
    Logger() {}

public:
    // Deleted copy constructor and assignment operator to prevent copies
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex);
        std::cout << "Log: " << message << std::endl;
    }
};

// Initialize the static members
Logger* Logger::instance = nullptr;
std::mutex Logger::mutex;

// Function to simulate logging from different classes and functions
void logFromFunction(const std::string& className, const std::string& functionName) {
    std::stringstream message;
    message << className << "::" << functionName;
    Logger::getInstance()->log(message.str());
}

// Three example classes with three functions each
class ClassA {
public:
    void func1() { logFromFunction("ClassA", "func1"); }
    void func2() { logFromFunction("ClassA", "func2"); }
    void func3() { logFromFunction("ClassA", "func3"); }
};

class ClassB {
public:
    void func1() { logFromFunction("ClassB", "func1"); }
    void func2() { logFromFunction("ClassB", "func2"); }
    void func3() { logFromFunction("ClassB", "func3"); }
};

class ClassC {
public:
    void func1() { logFromFunction("ClassC", "func1"); }
    void func2() { logFromFunction("ClassC", "func2"); }
    void func3() { logFromFunction("ClassC", "func3"); }
};

// Thread function to call random functions from the classes
void threadFunction() {
    ClassA a;
    ClassB b;
    ClassC c;

    srand(time(0));

    // Randomly call one of the nine functions
    int r = rand() % 9;
    std::cout << r << std::endl;
    switch (r) {
    case 0: a.func1(); break;
    case 1: a.func2(); break;
    case 2: a.func3(); break;
    case 3: b.func1(); break;
    case 4: b.func2(); break;
    case 5: b.func3(); break;
    case 6: c.func1(); break;
    case 7: c.func2(); break;
    case 8: c.func3(); break;
    }
}

int main() {
    std::vector<std::thread> threads;

    // Launching 5 threads
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(threadFunction));
    }

    // Joining all threads to the main thread
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
