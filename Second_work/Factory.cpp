#include "Factory.h"
#include "main_function.h"
#include "test.h"

std::shared_ptr<Creator> factory(type_of_inputs userChoice, Inputs input) {
	switch (userChoice) {
	case type_of_inputs::manualInput:{
		std::shared_ptr<Creator> (creator) = input.get_input_type(type_of_inputs::manualInput);
		return creator;
	}
	case type_of_inputs::randomInput: {
		std::shared_ptr<Creator>(creator) = input.get_input_type(type_of_inputs::randomInput);;
		return creator;
	}
	case type_of_inputs::fileInput: {
		std::shared_ptr<Creator>(creator) = input.get_input_type(type_of_inputs::fileInput);
		return creator;
	}
	default:
		std::cout << "Error in dactory" << std::endl;
		exit(0);
	}
}