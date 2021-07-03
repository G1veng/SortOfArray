#pragma once

#include "class.h"
#include <iostream>

const int RAND_MINIMUM_FOR_NUMBERS = -500;
const int RAND_MAXIMUM_FOR_NUMBERS = 500;
const int RAND_FOR_SIZE_OF_ARRAY = 30;
const int SIZE_OF_TEST = 5;

enum Errors_with_memory {
	out_of_memory = -2,
};

void init_array(Carray* array, Inputs choice);
int init_menu_size_of_array(Inputs choice);
void test(Carray* array);
Inputs menu(void);