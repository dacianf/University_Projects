#include "Date.h"

Date::Date(const Date & copyForDate)
{
	this->day = copyForDate.day;
	this->month = copyForDate.month;
	this->year = copyForDate.year;
}

Date::Date(const std::string & dateMDY)
{
	std::istringstream dateAsStream(dateMDY);
	std::string dateParameter;
	std::array<int, 3> dateParameters;
	dateParameters.fill(0);
	int index = { 0 };
	while (std::getline(dateAsStream, dateParameter, '-') && index < 3)
		dateParameters[index++] = atoi(dateParameter.c_str());
	this->month = dateParameters[0];
	this->day = dateParameters[1];
	this->year = dateParameters[2];
	if(!validateDate())
		throw DateExeption();
}

const std::string Date::toString()
{
	std::ostringstream dateAsStream;
	dateAsStream << *this;
	std::string stringToPrint = dateAsStream.str();
	return stringToPrint;
}

bool Date::validateDate()
{
	//validateDate validates a given date
	//Input: data - date type -- struct which has year, this->month && this->day as integers
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

bool Date::isLeapYear(int year)
{
	//checks if a given this->year has 29 || 28 days in February
	//Input: this->year - positiv integer
	//Output: True if given this->year is a leap one
	//		  False otherwise
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
