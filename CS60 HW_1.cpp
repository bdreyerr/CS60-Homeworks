// CS60 HW_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int main() {
	string input, compare;
	bool flag;

	ifstream inputStream;
	ifstream dict;

	inputStream.open("input.txt");
	if (inputStream.fail()) {
		cout << "input.txt failed to open" << endl;
		cin >> compare;
		exit(1);
	}
	while (!inputStream.eof()) {
		inputStream >> input;
		cout << input << endl;
		flag = false;
	
		dict.open("dict.txt");
		if (dict.fail()) {
			cout << "dict.txt failed to open" << endl;
			cin >> compare;
			exit(1);
		}

		while (!dict.eof()) {
			
			
			dict >> compare;
			if (compare == input)
				flag = true;
		}
		dict.close();

		if (flag == false)
			cout << input << endl;
	}
	cin >> compare;
	return 0;
}
