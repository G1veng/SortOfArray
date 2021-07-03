#pragma once

#include "class.h"
#include "input_output.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

enum Errors_with_files {
	fileIsNotExisting,
	fileWithIncorrecData,
};

void input_from_file(Carray* array);
std::string convert_int_to_string(int n);
void save_in_file(Carray& array);
void save_entered_data_in_file(Carray& array);
std::string get_string_txt(void);
int input_size_from_file(void);