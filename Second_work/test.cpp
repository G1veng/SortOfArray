#include "test.h"

void test(void) {
	std::string buffer = { 0 };
	bool errors[SIZE_OF_TEST] = { 0 };
	int countOfErrors = 0, sizeOfArray = 0;
	std::ifstream file("test.txt", std::ios_base::in);
	for (int i = 0; i < SIZE_OF_TEST; ++i) {
		file >> buffer;
		sizeOfArray = std::stoi(buffer);
		if (sizeOfArray <= 0) {
			continue;
		}
		Carray* item = new Carray(sizeOfArray);
		for (int j = 0; j < sizeOfArray; ++j) {
			file >> buffer;
			(*item)[j] = stoi(buffer);
		}
		main_function_for_sorting(item);
		for (int j = 0; j < sizeOfArray; ++j) {
			file >> buffer;
			if ((*item)[j] != stoi(buffer)) {
				std::cout << stoi(buffer) << std::endl;
				std::cout << (*item)[j] << std::endl;
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
		std::cout << "All tests are succeded" << std::endl;
}