#include "main_function.h"
#include "class.h"

void main_function_for_sorting(Carray* array) {
	int sizeOfArray = array->show_size() - 1;
	int temp = 0;
	for (int i = 0; i < array->show_size() - 1; ++i) {
		if ((*array)[i] % EVEN != 0) {
			for (sizeOfArray; sizeOfArray > i; --sizeOfArray) {
				if ((*array)[sizeOfArray] % EVEN == 0) {
					temp = (*array)[sizeOfArray];
					(*array)[sizeOfArray] = (*array)[i];
					(*array)[i] = temp;
					break;
				}
			}
		}
	}
}