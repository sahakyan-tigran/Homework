#pragma once

template <typename T>
class UniquePointer {
public:
	UniquePointer();
	UniquePointer(T*);
	UniquePointer(UniquePointer<T>&);
	UniquePointer<T>& operator=(UniquePointer<T>&);
	~UniquePointer<T>();

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

private:
	T* m_ptr;
};

template <typename T>
UniquePointer<T>::UniquePointer() : m_ptr(nullptr) {}
	
template <typename T>
UniquePointer<T>::UniquePointer(T* object) : m_ptr(object) {}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer<T>& object) : m_ptr(object.m_ptr) {	
	object.m_ptr = nullptr;
}

template <typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer<T>& object) {
	if (this != &object) {
		delete m_ptr;
		m_ptr = object.m_ptr;
		object.m_ptr = nullptr;
	}
	return *this;
}

template <typename T>
UniquePointer<T>::~UniquePointer() {
	delete m_ptr;
}

template <typename T>
T& UniquePointer<T>::operator*() {
	if (m_ptr == nullptr) {
		throw std::exception("Impossible");
	}
	return *m_ptr;
}

template <typename T>
const T& UniquePointer<T>::operator*() const {
	if (m_ptr == nullptr) {
		throw std::exception("Impossible");
	}
	return *m_ptr;
}

template <typename T>
T* UniquePointer<T>::operator->() {
	return m_ptr;
}

template <typename T>
const T* UniquePointer<T>::operator->() const {
	return m_ptr;
}