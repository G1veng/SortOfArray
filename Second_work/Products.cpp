#include "Products.h"

ProductsOfFileInput::ProductsOfFileInput() { }
ProductsOfConsoleInput::ProductsOfConsoleInput() {}
ProductsOfRandomInput::ProductsOfRandomInput(){}

Carray* ProductsOfConsoleInput::get_input(void) {
	int sizeOfArray = 0;
	std::cout << "Please enter size of array" << std::endl;
	do {
			sizeOfArray = input_digit();
			if (sizeOfArray <= 0)
				std::cout << "Error" << std::endl;
	} while (sizeOfArray <= 0);
	Carray* array = new Carray(sizeOfArray);
	std::cout << "Please enter " << array->show_size() << " numbers" << std::endl;
	set_text_color(RED);
	for (int i = 0; i < array->show_size(); ++i) {
			std::cout << i + 1 << " number ->\t";
			(*array)[i] = input_digit();
	}
	set_text_color(BLACK);
	save_entered_data_in_file(*array);
	return array;
}

Carray* ProductsOfFileInput::get_input(void) {
	std::cout << "Enter please folder with size of array" << std::endl;
	int sizeOfArray = input_size_from_file();
	Carray* array = new Carray(sizeOfArray);
	std::cout << "Size of array ->\t" << sizeOfArray << std::endl;
	array->set_size(sizeOfArray);
	std::cout << "Enter please folder with numbers of array" << std::endl;
	input_from_file(array);
	return array;
}

Carray* ProductsOfRandomInput::get_input(void) {
	srand(static_cast <unsigned> (time(NULL)));
	int sizeOfArray = 0;
	sizeOfArray = 1 + rand() % (RAND_FOR_SIZE_OF_ARRAY);
	std::cout << "Size of array ->\t" << sizeOfArray << std::endl;
	Carray* array = new Carray(sizeOfArray);
	set_text_color(RED);
	for (int i = 0; i < array->show_size(); ++i) {
		(*array)[i] = RAND_MINIMUM_FOR_NUMBERS + rand() % (RAND_MAXIMUM_FOR_NUMBERS);
		std::cout << i + 1 << " number of array ->\t" << (*array)[i] << std::endl;
	}
	set_text_color(BLACK);
	save_entered_data_in_file(*array);
	return array;
}