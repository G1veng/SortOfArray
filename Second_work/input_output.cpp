#include "input_output.h"
#include "text_colour.h"
#include "work_with_files.h"

int input_digit(void) {
	int digit = 0;
	do {
		while ((std::cin >> digit) && (std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return digit;
		}
		std::cout << "Error, please enter number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (true);
}

bool end_the_program(void) {
	std::string buffer = { 0 };
	int i = 0;
	std::cin >> buffer;
	do {
		if ((buffer[i] > CHAR_NINE || buffer[i] < CHAR_ZERO) && buffer[i] != CHAR_MINUS) {
			while (getchar() != '\n');
			return false;
		}
		++i;
	} while (buffer[i] != '\0');
	while (getchar() != '\n');
	return true;
}

void output_array(Carray& array) {
	std::cout << "Sorted array:" << std::endl;
	set_text_color(GREEN);
	for (int i = 0; i < array.show_size(); ++i) {
		std::cout << i + 1 << " number ->\t" << array[i] << std::endl;
	}
	set_text_color(BLACK);
	save_in_file(array);
}

bool is_string_only_digits(std::string someString) {
	size_t sizeOfString = someString.size();
	for (unsigned int i = 0; i < sizeOfString; ++i) {
		if ((someString[i] > CHAR_NINE || someString[i] < CHAR_ZERO) && someString[i] != CHAR_MINUS)
			return false;
	}
	return true;
}