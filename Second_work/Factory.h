#pragma once

#include "creator_of_main_inputs.h"

std::shared_ptr<Creator> factory(type_of_inputs userChoice, Inputs input);
