#include "Factory.h"
#include "test.h"

int main(void){
	std::cout << "Welcome. Laborator work, option 3, number 2 by student of 403 group: Shishko Daniil Yerevich" << std::endl;
	std::cout << "Aim of program: with classes sort the array, if all even numbers in left side of array, odd in left side" << std::endl;
	Inputs input;
	do {
		std::cout << "1 - to console input" << std::endl;
		std::cout << "2 - to random input" << std::endl;
		std::cout << "3 - to file input" << std::endl;
		std::cout << "4 - to test" << std::endl;
		type_of_inputs userChoice = static_cast<type_of_inputs>(input_digit());
			if (userChoice < type_of_inputs::testOfProgram && userChoice > type_of_inputs::mainFunction) {
				std::shared_ptr<Creator>(creator) = factory(userChoice, input);
				Carray* array = creator->get_array();
				std::shared_ptr<Carray> sharedArray(array);
				main_function_for_sorting(array);
				output_array(*array);
			}
			if(userChoice == type_of_inputs::testOfProgram)
				test();
			else {
				std::cout << "Wrong enter" << std::endl;
			}
		std::cout << "Enter 1 to repeat program" << std::endl;
		std::cout << "Enter 0 to end program" << std::endl;
	} while (input_digit());
	return 0;
}