// CS60 HW3.cpp : Defines the entry point for the console application.


//This program will hold an array of integers in class blob. The append function can be use to add an integer to the array, making the size of the array larger.

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

static const int MAX_ELEMENT = 100;
class Blob {
public:
	//Constructors
	Blob(int size);
	Blob();
	//Member functions
	int size();
	void append(int in);
	//getter
	int get(int index) const;
	//Operators
	int& operator [](int index);
	

private:
	int data_[MAX_ELEMENT];
	int num_element_;
};
//Constructors
Blob::Blob(int size) {
	assert(size < MAX_ELEMENT);
	num_element_ = size;
}
Blob::Blob() {
	num_element_ = 0;
}
//Member functions
int Blob::size() {
	return num_element_;
}
void Blob::append(int in) {
	data_[size()] = in;
	num_element_++;
}
//getter
int Blob::get(int index) const{
	return data_[index];
}
//Operators
int& Blob::operator[](int index) {
	return data_[index];
}
//ostream overload
ostream& operator <<(ostream& out, Blob b){
	out << "[ ";
	for (int i = 0; i < b.size(); i++) {
		out << b.get(i) << " " ;
	}
	out << " ]";
	return out;
}

int main()
{
	srand(time(NULL)); // seed the time
	const int kNumElements = 10;
	Blob a;
	//Append some random numbers to the blob
	for (int i = 0; i < kNumElements; ++i) {
		int r = rand() % 100;
		a.append(r);
	}
	cout << a << endl;
	//double the number at all indicies
	for(int i = 0; i < kNumElements; ++i){
		a[i] = 2 * a[i];
	}
	cout << a << endl;
	//Lets append few more numbers.
	a.append(111);
	a.append(222);
	cout << a << endl;
	system("pause");
	return 0;
}

