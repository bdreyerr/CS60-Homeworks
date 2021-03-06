﻿// CS60 HW4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class IntBag {
	const static int CAPACITY = 128;
	const static int MULT = 2;
public:
	IntBag(); //Defualt Constructor
	IntBag(const IntBag &a);//Copy Constructor
	~IntBag();//Deconstructor
	void operator =(const IntBag& a);//= operator overload(same as Copy Construcor)
	int operator [](int index);//[] operator that returns [index]
	void add(const int item);//add method which adds int item to the array
	int getSize()const;//getter function for size_
	void fill(int c);//fill method which fills in the entire array with int c
	void setSize(int newsize);//setSize method which changes the size to int newsize
	void clear();//clear method which wipes the array, resets to intial value
	void deleteFunc(int pos);//delete method which will delete one index from the array

private:
	int *array_;
	int size_;

};

IntBag::IntBag() {
	size_ = 100;
	array_ = new int[size_];

}

IntBag::IntBag(const IntBag &a) {
	size_ = a.getSize();
	array_ = new int[size_];
	for (int i = 0; i < size_; i++) {
		array_[i] = a.array_[i];
	}

}

IntBag::~IntBag() {
	delete[] array_;
}

void IntBag::operator =(const IntBag& a) {
	size_ = a.getSize();
	array_ = new int[size_];
	for (int i = 0; i < size_; i++) {
		array_[i] = a.array_[i];
	}

}

int IntBag::operator [](int index) {
	return array_[index];
}

void IntBag::add(const int item) {
	if (size_ >= CAPACITY) {
		size_ *= MULT;
	}
	size_++;
	array_ = new int[size_];
	array_[size_ - 1] = item;
}

int IntBag::getSize()const {
	return size_;
}

void IntBag::setSize(int newsize) {
	size_ = newsize;
	array_ = new int[size_];
}

void IntBag::fill(int c) {
	for (int i = 0; i < size_; i++) {
		array_[i] = c;
	}
}

void IntBag::clear() {
	delete[] array_;
	size_ = 100;
	array_ = new int[size_];

}

void IntBag::deleteFunc(int pos) { //Do i need to make a temp array and then swap values?
	array_[pos] = 0;

}

ostream& operator <<(ostream& out, IntBag &a) {
	out << "[ ";
	for (int i = 0; i < a.getSize(); i++) {
		out << a[i] << " ";
	}
	out << " ]";
	return out;
}






int main()
{
	IntBag a;
	cout << "Size:" << a.getSize() << endl << "Array:" << a << endl << endl;

	a.setSize(3);
	cout << "Size:" << a.getSize() << endl << "Array:" << a << endl << endl;

	a.add(55);
	cout << "Size:" << a.getSize() << endl << "Array:" << a << endl << endl;


	IntBag b(a);
	cout << "Size:" << b.getSize() << endl << "Array:" << b << endl << endl;

	cout << "b[3]: " << b[3] << endl << endl;

	b.fill(6);
	cout << "Size:" << b.getSize() << endl << "Array:" << b << endl << endl;

	b.deleteFunc(3);
	cout << "Size:" << b.getSize() << endl << "Array:" << b << endl << endl;


	a.clear();
	cout << "Size:" << a.getSize() << endl << "Array:" << a << endl << endl;

	b = a;
	cout << "Size:" << b.getSize() << endl << "Array:" << b << endl << endl;


	system("pause");
    return 0;
}

