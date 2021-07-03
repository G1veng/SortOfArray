#include "class.h"

	Carray :: Carray(int sizeOfArray) {
		sizeOfClassArray = sizeOfArray;
		array = new int[sizeOfClassArray];
	}
	Carray ::~Carray() {
		delete[] array;
	}
	int&  Carray :: operator[](int index) {
		if (index >= sizeOfClassArray)
			exit(OUT_OF_RANGE);
		return array[index];
	}
	int Carray :: show_size(void) {
		return sizeOfClassArray;
	}

	void Carray::set_size(int sizeOfArray) {
		sizeOfClassArray = sizeOfArray;
	}