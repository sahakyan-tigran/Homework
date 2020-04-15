#pragma once

#include <exception>

template <typename T>
class SharedPointer {
public:
	SharedPointer(T* = nullptr);
	SharedPointer(SharedPointer<T>&);
	SharedPointer<T>& operator=(SharedPointer<T>&);
	~SharedPointer();

	T& operator*();
	const T& operator*() const;

	T* operator->();
	const T* operator->() const;

private:
	 void deallocate();

private:
	T* m_ptr;
	int* m_reference_count;
};

template <typename T>
SharedPointer<T>::SharedPointer(T* object) : m_ptr(object) {
	m_reference_count = new int((object == nullptr) ? 0 : 1);
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T>& object) : m_ptr(object.m_ptr) {
	++(*object.m_reference_count);
	m_reference_count = object.m_reference_count;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer<T>& object) {
	if (this != &object) {
		if (--(*m_reference_count) == 0) {
			delete m_ptr;
			delete m_reference_count;
		}
		m_ptr = object.m_ptr;
		++object.m_reference_count;
		m_reference_count = object.m_reference_count;
	}
	return *this;
}

template <typename T>
SharedPointer<T>::~SharedPointer() {
	deallocate();
}

template <typename T>
T& SharedPointer<T>::operator*() {
	if (m_ptr == nullptr) {
		throw std::exception("Impossible");
	}
	return *m_ptr;
}

template <typename T>
const T& SharedPointer<T>::operator*() const {
	if (m_ptr == nullptr) {
		throw std::exception("Impossible");
	}
	return *m_ptr;
}

template <typename T>
T* SharedPointer<T>::operator->() {
	return m_ptr;
}

template <typename T>
const T* SharedPointer<T>::operator->() const {
	return m_ptr;
}

template <typename T>
void SharedPointer<T>::deallocate() {
	if (--(*(m_reference_count)) == 0) {
		delete m_ptr;
		delete m_reference_count;
	}
}