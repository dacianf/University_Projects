#pragma once
#include <stdexcept>

class SecurityRecordException : public std::runtime_error {
public:
	explicit SecurityRecordException() : runtime_error("Invalid security record!") {}
};