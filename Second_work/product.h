#pragma once

#include "class.h"
#include "text_colour.h"
#include "class.h"
#include <memory>

const int RAND_MINIMUM_FOR_NUMBERS = -500;
const int RAND_MAXIMUM_FOR_NUMBERS = 1000;
const int RAND_FOR_SIZE_OF_ARRAY = 30;

class Product {
public:
	virtual ~Product() = default;
	virtual Carray* get_input() = 0;
};