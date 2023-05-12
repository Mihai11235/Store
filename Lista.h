#pragma once
#include "produs.h"

template<typename T>
class IteratorList;

//typedef int T;

template<typename T>
class list {
	friend class IteratorList<T>;
private:
	int cap;
	int len;
	T* elems;

	void ensure_capacity();
public:
	list();

	//rule of 3
	list(const list&);
	list& operator=(const list&);
	~list();

	//rule of 5
	//List(const T&&);
	//List operator=(const T&&);


	void push_back(const T& elem);
	long long size() const noexcept;
	void erase(IteratorList<T>);
	IteratorList<T> begin() const noexcept;
	IteratorList<T> end() const noexcept;
	T& operator[](int) noexcept;
	T& front() const;
	T& get(int) const;
};







template<typename T>
list<T>::list() :len{ 0 }, cap{ 1 }, elems{ new T[cap] } {};

template<typename T>
list<T>::list(const list& l) {
	elems = new T[l.cap];
	for (int i = 0; i < l.len; i++)
		elems[i] = l.elems[i];
	cap = l.cap;
	len = l.len;
}


template<typename T>
void list<T>::ensure_capacity() {
	if (len == cap) {
		T* aux = new T[cap * 2];
		for (int i = 0; i < len; i++)
			aux[i] = elems[i];
		delete[] elems;
		elems = aux;
		cap *= 2;
	}
}

template<typename T>
list<T>& list<T>::operator=(const list& l) {
	if (this == &l)
		return *this;
	delete[] elems;

	elems = new T[l.cap];
	for (int i = 0; i < l.len; i++)
		elems[i] = l.elems[i];
	cap = l.cap;
	len = l.len;
	return *this;
}

template<typename T>
list<T>::~list() {
	delete[] elems;
}

template<typename T>
void list<T>::push_back(const T& elem) {
	ensure_capacity();
	elems[len++] = elem;
}

template<typename T>
long long list<T>::size() const noexcept {
	return len;
}

template<typename T>
void list<T>::erase(IteratorList<T> iter) {
	auto poz = iter.curent - elems;
	for (auto i = poz; i < len - 1; i++) {
		elems[i] = elems[i + 1];
	}
	len -= 1;
}

template<typename T>
IteratorList<T> list<T>::begin() const noexcept {
	return IteratorList<T>(*this);
}

template<typename T>
IteratorList<T> list<T>::end() const noexcept {
	return IteratorList<T>(*this, len);
}

template<typename T>
T& list<T>::operator[](int poz) noexcept {
	return elems[poz];
}

template<typename T>
T& list<T>::front() const{
	return elems[0];
}

template<typename T>
T& list<T>::get(int poz) const {
	return elems[poz];
}






template<typename T>
class IteratorList {
	friend class list<T>;

private:
	const list<T>& l;
	const int& len;
	T* curent = l.elems + len;

public:
	IteratorList(const list<T>& l) noexcept;
	IteratorList(const list<T>& l, int len) noexcept;

	bool valid() noexcept;
	T& operator*() noexcept;
	IteratorList<T>& operator++() noexcept;
	T* operator->() noexcept;
	bool operator!= (const IteratorList<T>& i) noexcept;
	IteratorList<T>& operator+(int) noexcept;
};







template<typename T>
IteratorList<T>::IteratorList(const list<T>& l) noexcept :l{ l }, len{ 0 } {};

template<typename T>
IteratorList<T>::IteratorList(const list<T>& l, int len) noexcept :l{ l }, len{ len } {};

template<typename T>
bool IteratorList<T>::valid() noexcept {
	return curent < l.elems + len;
}

template<typename T>
T& IteratorList<T>::operator*() noexcept {
	return *curent;
}

template<typename T>
IteratorList<T>& IteratorList<T>::operator++() noexcept {
	curent += 1;
	return *this;
}

template<typename T>
T* IteratorList<T>::operator->() noexcept {
	return curent;
}

template<typename T>
bool IteratorList<T>::operator!= (const IteratorList& i) noexcept {
	return curent != i.curent;
}

template<typename T>
IteratorList<T>& IteratorList<T>::operator+(int i) noexcept {
	curent += i;
	return *this;
}

