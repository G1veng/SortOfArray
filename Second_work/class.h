#pragma once

#include <stdlib.h>

const int OUT_OF_RANGE = 0;

class Carray {
public:
	Carray(int sizeOfArray);
	~Carray();
	int& operator[](int index);
	int show_size(void);
	void set_size(int sizeOfArray);
private:
	int* array;
	int sizeOfClassArray;
};