#pragma once
#pragma once
template<typename T>
class UniquePointer {
private:
	T* m_newMem;

public:
	UniquePointer<T>(T* ptr = nullptr) :m_newMem(ptr) {
		std::cout << "Unique Pointer Ctor was called\n";
	}

	UniquePointer<T>(const UniquePointer<T>& ptr) = delete;
	UniquePointer<T>& operator=(const UniquePointer<T>& ptr) = delete;

	UniquePointer<T>(UniquePointer<T>&& ptr) noexcept {
		m_newMem = ptr.m_newMem;
		ptr.m_newMem = nullptr;
	}

	UniquePointer<T>& operator=(UniquePointer<T>&& ptr) noexcept {
		if (this != &ptr) {
			if (m_newMem)
				delete m_newMem;

			m_newMem = ptr.m_newMem;
			ptr.m_newMem = nullptr;
		}
		return *this;
	}

	void reset(T* ptr) {
		if (m_newMem)
			delete m_newMem;
		m_newMem = ptr;
	}

	void reset() {
		if (m_newMem)
			delete m_newMem;

		m_newMem = nullptr;
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
	~UniquePointer() {
		if (m_newMem) {
			delete m_newMem;
			m_newMem = nullptr;
		}
	}
};