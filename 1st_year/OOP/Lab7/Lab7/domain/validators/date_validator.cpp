#include "date_validator.h"



date_validator::date_validator()
{
	//validateDate validates a given date
	//Input: data - date type -- struct which has year, this->month and this->day as integers
	//Output: 1 - if the given date is valid
	//		  0 - otherwise
	if (this->day < 1 || this->day > 31 || this->month < 1 || this->month > 12 || this->year < 1)
		return false;
	if (((this->month % 2 == 1 && this->month <= 7) || (this->month % 2 == 0 && this->month >= 8)) && this->day > 31)
		return false;
	if (((this->month % 2 == 0 && this->month <= 7) || (this->month % 2 == 1 && this->month >= 8)) && this->day > 30)
		return false;
	if (this->month == 2 && isLeapYear(this->year) && this->day > 29)
		return false;
	if (this->month == 2 && !isLeapYear(this->year) && this->day > 28)
		return false;
	return true;
}


date_validator::date_validator(Date& date)
{
	this->dateToTest = date;
}

void date_validator::validate()
{
}

date_validator::~date_validator()
{
}
