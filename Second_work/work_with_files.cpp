#include "work_with_files.h"
#include "text_colour.h"

void input_from_file(Carray* array) {
	std::string path = { 0 };
	do {
		path = get_string_txt();
		std::ifstream file(path, std::ios_base::in);
		try {
			static_cast<void>(fs::is_regular_file(path));
		}
		catch (...) {
			std::cout << "Error, please try again" << std::endl;
			continue;
		}
		if (!(file.is_open())) {
			std::cout << "File is not existing" << std::endl;
			file.close();
		}
		if ((file.is_open()) || !file.fail()) {
			file.close();
			break;
		}
	} while (true);
	std::ifstream file(path, std::ios_base::in);
	file >> path;
	std::cout << "Size of array ->\t" << array->show_size() << std::endl;
	set_text_color(RED);
	for (int i = 0; i < array->show_size(); ++i) {
		file >> path;
		if (!(is_string_only_digits(path))) {
			std::cout << "File with incorrect data" << std::endl;
			exit(fileWithIncorrecData);
		}
		(*array)[i] = std::stoi(path);
		std::cout << i + 1 << " number of array ->\t" << (*array)[i] << std::endl;
	}
	file.close();
	set_text_color(BLACK);
}

int input_size_from_file(void) {
	std::string path = { 0 };
	do {
		path = get_string_txt();
		std::ifstream file(path, std::ios_base::in);
		try {
			static_cast<void>(fs::is_regular_file(path));
		}
		catch (...) {
			std::cout << "Error, please try again" << std::endl;
			continue;
		}
		if (!(file.is_open())) {
			std::cout << "File is not existing" << std::endl;
			file.close();
		}
		if ((file.is_open()) || !file.fail()) {
			file.close();
			break;
		}
	} while (true);
	std::ifstream file(path, std::ios_base::in);
	file >> path;
	if (!(is_string_only_digits(path))) {
		std::cout << "File with incorrect data" << std::endl;
		exit(fileWithIncorrecData);
	}
	file.close();
	return std::stoi(path);
}

std::string get_string_txt(void) {
	std::string path;
	std::cout << "Enter way to folder please:" << std::endl;
	std::cin >> path;
	while (getchar() != '\n');
	return path;
}

std::string convert_int_to_string(int n) {
	std::ostringstream someString;
	someString << n;
	return someString.str();
}

void save_in_file(Carray& array) {
	std::string outputInFile = { 0 }, path = { 0 };
	std::cout << "You want to save data in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	switch (input_digit()) {
	case true: {
			do{
				path = get_string_txt();
				std::ofstream file(path, std::ios_base::in);
				try {
					static_cast<void>(fs::is_regular_file(path));
				}
				catch (...) {
					std::cout << "Error, please try again" << std::endl;
					continue;
				}
				if ((file.is_open())) {
					std::cout << "You want to rewrite file?" << std::endl;
					std::cout << "1 - yes" << std::endl;
					std::cout << "2 - no" << std::endl;
					if (input_digit() == 2) {
						file.close();
						continue;
					}
				}
				break;
			} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
		outputInFile = convert_int_to_string(array.show_size());
		file << outputInFile << " ";
		for (int count = 0; count < array.show_size(); ++count) {
			outputInFile = { 0 };
			outputInFile = convert_int_to_string(array[count]);
			file << outputInFile << " ";
		}
		file.close();
		std::cout << "Result saved" << std::endl;
		break;
	}
	default:;
	}
}

void save_entered_data_in_file(Carray& array) {
	std::string path = { 0 }, outputInFile = { 0 };
	std::cout << "You want to save results in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	switch (input_digit()) {
	case true: {
		do {
			path = get_string_txt();
			std::ifstream file(path, std::ios_base::in);
			try {
				bool trueOrFalse = fs::is_regular_file(path);
			}
			catch (...) {
				std::cout << "Error, please try again" << std::endl;
				continue;
			}
			if (file.is_open()) {
				std::cout << "You want to rewrite file?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "2 - no" << std::endl;
				if (input_digit() == 2) {
					file.close();
					continue;
				}
			}
			break;
		} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
		outputInFile = convert_int_to_string(array.show_size());
		file << outputInFile << " ";
		for (int count = 0; count < array.show_size(); ++count) {
			outputInFile = { 0 };
			outputInFile = convert_int_to_string(array[count]);
			file << outputInFile << " ";
		}
		file.close();
		std::cout << "Result saved" << std::endl;
	}
	default:;
	}
}