#pragma once
#include <stdexcept>

class DateExeption : public std::runtime_error {
public:
	explicit DateExeption() : runtime_error("Invalid date!") {}
};