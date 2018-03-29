#ifndef FILMTAR_SET_HPP
#define FILMTAR_SET_HPP

#include "film.hpp"
#include "csaladi.hpp"
#include "dokumentum.hpp"

template <class T>
class Set {
	size_t num;
	T *rec;
public:
	Set() :rec(NULL),num(0) {}
	Set(const Set&);
	~Set();
	Set& operator = (const Set&);

	bool isIn(const T&) const;
	bool isEmpty() const;

	size_t size() const;

	void clear();
	void push(const T&);
	T& pop();

	std::ostream & printAll(std::ostream &) const;
};

template <class T>
Set<T>::Set(const Set<T>& ref) {
	num = ref.num;
	rec = new T[num];
	for(size_t i=0; i<num; i++)
		rec[i] = ref.rec[i];
}

template <class T>
Set<T>& Set<T>::operator = (const Set<T>& ref) {
	if( this != &ref){
		delete[] rec;
		num = ref.num;
		rec = new T[num];
		for(size_t i=0; i<num; i++)
			rec[i] = ref.rec[i];
	}
	return *this;
}

template <class T>
bool Set<T>::isIn(const T& ref) const {
	for(size_t i=0; i<num; i++)
		if(this == &ref)
			return true;
	return false;
}

template <class T>
bool Set<T>::isEmpty() const {
	if (NULL == rec && 1 > num)
		return true;
	return false;
}

template <class T>
size_t Set<T>::size() const {
	return num;
}

template <class T>
void Set<T>::clear() {
	delete[] rec;
	num = 0;
	rec = NULL;
}

template <class T>
void Set<T>::push(const T& ref) {
	if(isIn(ref)) return;
	T* t_new = new T[num+1];
	for(size_t i=0; i<num; i++)
		t_new[i] = rec[i];
	t_new[num++] = ref;
	delete[] rec;
	rec = t_new;
}

template <class T>
T& Set<T>::pop() {
	T retval = rec[num - 1];
	T* t_new = new T[num];
	for(size_t i=0; i<num-1; i++)
		t_new[i] = rec[i];
	delete[] rec;
	rec = t_new;
	return retval;
}

template <class T>
std::ostream & Set<T>::printAll(std::ostream & os) const {
	for(size_t i=0; i < num; i++ ) {
		os << "+-------------------------------------------------------------+" << std::endl;
		os << rec[i];
		os << "+-------------------------------------------------------------+" << std::endl;
	}
	return os;
}

template <class T>
std::ostream & operator << (std::ostream & os, const Set<T> & st) {
	return st.printAll(os);
}

#endif
