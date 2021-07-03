#pragma once

#include <iostream>
#include "class.h"
#include "input_output.h"

/*enum class type_of_inputs {
	mainFunction,
	manualInput,
	randomInput,
	fileInput,
	testOfProgram
};*/

enum class type_of_primal_inputs {
	primalConsoleInput = 1,
	primalFileInput
};

/*class Inputs {
public:
	type_of_inputs classUserChoice;
	Inputs(type_of_primal_inputs input);
	virtual type_of_inputs choice(type_of_primal_inputs input);
	virtual ~Inputs();
};*/