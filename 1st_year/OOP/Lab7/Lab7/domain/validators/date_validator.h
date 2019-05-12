#pragma once
#include "../Date.h"
class date_validator
{
private:
	Date dateToTest;
public:
	date_validator(Date&);
	void validate();
	~date_validator();
};

