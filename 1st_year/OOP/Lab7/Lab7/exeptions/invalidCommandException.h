#pragma once
#include <stdexcept>
#include <string>

class InvalidCommandException : public std::runtime_error {
public:
	explicit InvalidCommandException(std::string errorName) : runtime_error(errorName) {}
};