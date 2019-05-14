#pragma once
#include <stdexcept>
#include <string>

class ServiceExeption : public std::runtime_error {
public:
	explicit ServiceExeption(std::string errorName) : runtime_error(errorName) {}
};
