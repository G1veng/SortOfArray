#pragma once

#include <string>
#include <iostream>
#include "class.h"
#include <limits>
#include <ios>

const int CHAR_NINE = 57;
const int CHAR_ZERO = 48;
const int CHAR_MINUS = 45;

bool end_the_program(void);
void output_array(Carray& array);
bool is_string_only_digits(std::string someString);
int input_digit(void);