#pragma once

#include "Products.h"

class Creator {
public:
	virtual ~Creator() = default;
	virtual Product* factory_method() = 0;
	Carray* get_array();
};

class Inputs final {
public:
	Inputs();
	~Inputs() = default;
	std::shared_ptr <Creator> get_input_type(type_of_inputs input);
private:
	std::shared_ptr<Creator> manual;
	std::shared_ptr<Creator> random;
	std::shared_ptr<Creator> file;
};

class CreatorOfManualInput final : public Creator {
public:
	CreatorOfManualInput();
	virtual ~CreatorOfManualInput() = default;
	virtual Product* factory_method() override;
};

class CreatorOfRandomInput final : public Creator {
public:
	CreatorOfRandomInput();
	virtual ~CreatorOfRandomInput() = default;
	virtual Product* factory_method() override;
};

class CreatorOfFileInput final : public Creator {
public:
	CreatorOfFileInput();
	virtual ~CreatorOfFileInput() = default;
	virtual Product* factory_method() override;
};
