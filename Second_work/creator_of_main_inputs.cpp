#include"creator_of_main_inputs.h"
#include "main_function.h"
#include "input_output.h"

CreatorOfManualInput::CreatorOfManualInput() {}
CreatorOfFileInput::CreatorOfFileInput(){}
CreatorOfRandomInput::CreatorOfRandomInput(){}
Inputs::Inputs() {}

Product* CreatorOfManualInput::factory_method() {
	Product* product = new ProductsOfConsoleInput();
	return product;
}

Product* CreatorOfFileInput::factory_method() {
	Product* product = new ProductsOfFileInput();
	return product;
}

Product* CreatorOfRandomInput::factory_method() {
	Product* product = new ProductsOfRandomInput();
	return product;
}

Carray* Creator::get_array() {
	Product* product = this->factory_method();
	std::shared_ptr<Product> sharedProduct(product);
	Carray* array = product->get_input();
	return array;
}

std::shared_ptr<Creator> Inputs::get_input_type(type_of_inputs input) {
	switch (input) {
	case type_of_inputs::manualInput: {
		if (manual == nullptr)
			manual = std::make_shared<CreatorOfManualInput>(CreatorOfManualInput());
		return manual;
		}
	case type_of_inputs::randomInput: {
		if(random == nullptr)
			random = std::make_shared<CreatorOfRandomInput>(CreatorOfRandomInput());
		return random;
	}
	case type_of_inputs::fileInput: {
		if(file == nullptr)
			file = std::make_shared<CreatorOfFileInput>(CreatorOfFileInput());
		return file;
	}
	default:
		std::cout << "Error in creator_of_main_inputs" << std::endl;
		exit(0);
	}
}