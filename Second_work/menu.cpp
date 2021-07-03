#include "menu.h"
#include "input_output.h"
#include "text_colour.h"
#include "work_with_files.h"
#include "main_function.h"

void init_array(Carray* array, Inputs choice) {
	srand((unsigned)time(NULL));
	switch (choice) {
	case Inputs::manualInput: {
		std::cout << "Please enter " << array->show_size() << " numbers" << std::endl;
		set_text_color(RED);
		for (int i = 0; i < array->show_size(); ++i) {
			std::cout << i + 1 << " number ->\t";
			(*array)[i] = input_digit();
		}
		set_text_color(BLACK);
		break;
	}
	case Inputs::randomInput: {
		set_text_color(RED);
		for (int i = 0; i < array->show_size(); ++i) {
			(*array)[i] = RAND_MINIMUM_FOR_NUMBERS + rand() % (RAND_MAXIMUM_FOR_NUMBERS);
			std::cout << i + 1 << " number of array ->\t" << (*array)[i] << std::endl;
		}
		set_text_color(BLACK);
		break;
	}
	case Inputs::fileInput: {
		std::cout << "Enter please folder with numbers of array" << std::endl;
		input_from_file(array);
		break;
	}
	case Inputs::testOfProgram: 
		test(array);
		//break;
	default:;
	}
}

int init_menu_size_of_array(Inputs choice) {
	int sizeOfArray = 0;
	srand((unsigned)time(NULL));
	do {
		switch (choice) {
		case Inputs::manualInput: {
			std::cout << "Please enter size of array" << std::endl;
			do {
				sizeOfArray = input_digit();
				if (sizeOfArray <= 0)
					std::cout << "Error" << std::endl;
			} while (sizeOfArray <= 0);
			return sizeOfArray;
			break;
		}
		case Inputs::randomInput: {
			sizeOfArray = 1 + rand() % (RAND_FOR_SIZE_OF_ARRAY);
			std::cout << "Size of array ->\t" << sizeOfArray << std::endl;
			return sizeOfArray;
			break;
		}
		case Inputs::fileInput: {
			std::cout << "Enter please folder with size of array" << std::endl;
			int sizeOfArray = input_size_from_file();
			std::cout << "Size of array ->\t" << sizeOfArray << std::endl;
			return sizeOfArray;
			break;
		}
		case Inputs::testOfProgram:
			return 0;
			break;
		}
	} while (true);
}

void test(Carray* array) {
	std::string buffer = { 0 };
	bool errors[SIZE_OF_TEST] = { 0 };
	int countOfErrors = 0, sizeOfArray = 0;
	std::ifstream file("test.txt", std::ios_base::in);
	if (!file.is_open()) {
		std::cout << "File is not existing" << std::endl;
		exit(fileIsNotExisting);
	}
	for (int i = 0; i < SIZE_OF_TEST; ++i) {
		file >> buffer;
		sizeOfArray = std::stoi(buffer);
		if (sizeOfArray <= 0) {
			continue;
		}
		Carray array(sizeOfArray);
		for (int j = 0; j < sizeOfArray; ++j) {
			file >> buffer;
			array[j] = stoi(buffer);
		}
		main_function_for_sorting(&array);
		for (int j = 0; j < sizeOfArray; ++j) {
			file >> buffer;
			if (array[j] != stoi(buffer)) {
				std::cout << stoi(buffer) << std::endl;
				std::cout << array[j] << std::endl;
				errors[i] = true;
				countOfErrors = i + 1;
			}
		}
	}
	for (int i = 0; i < SIZE_OF_TEST; ++i)
		if (errors[i] == true) {
			std::cout << "Error in " << i + 1 << " test" << std::endl;
		}
	if (countOfErrors == 0)
		std::cout << "All test is succeded" << std::endl;
}

Inputs menu(void) {
	int choice (0);
	std::cout << "1 - to manual input" << std::endl;
	std::cout << "2 - to random input" << std::endl;
	std::cout << "3 - to file input" << std::endl;
	std::cout << "4 - to test program" << std::endl;
	do {
		choice = input_digit();
		switch (static_cast<Inputs>(choice)) {
		case Inputs::manualInput:
			return Inputs::manualInput;
		case Inputs::randomInput:
			return Inputs::randomInput;
		case Inputs::fileInput:
			return Inputs::fileInput;
		case Inputs::testOfProgram:
			return Inputs::testOfProgram;
		default:
			std::cout << "There is no these choice, please try again" << std::endl;
		}
	} while (true);
}