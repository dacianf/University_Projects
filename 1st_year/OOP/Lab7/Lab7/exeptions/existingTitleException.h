#pragma once
#include <stdexcept>

class ExistingTitleException : public std::runtime_error {
public:
	explicit ExistingTitleException() : runtime_error("This title already exists in the repo!") {}
};