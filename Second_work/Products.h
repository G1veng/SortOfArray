#pragma once

#include "product.h"
#include "input_output.h"
#include "work_with_files.h"

enum class type_of_inputs {
	mainFunction,
	manualInput,
	randomInput,
	fileInput,
	testOfProgram
};

class ProductsOfConsoleInput final : public Product {
public:
	ProductsOfConsoleInput();
	Carray* get_input() override;
};

class ProductsOfFileInput final : public Product {
public:
	ProductsOfFileInput();
  Carray* get_input() override;
};

class ProductsOfRandomInput final : public Product {
public:
	ProductsOfRandomInput();
	Carray* get_input() override;
};
