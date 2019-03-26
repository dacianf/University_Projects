#include "Date.h"

Date::Date(std::string & date)
{
	if (date.length() != 10)throw "Date incorect! It must have the form MM-DD-YYYY!";
	std::string dayAsString;
	std::string monthAsString;
	std::string yearAsString;
	monthAsString.append(date, 2);
	monthAsString.append("\n");
	dayAsString.append(date, 3, 2);
	dayAsString.append("\n");
	yearAsString.append(date, 6, 4);
	yearAsString.append("\n");
	
	this->month = std::stoi(monthAsString);
	this->day = std::stoi(dayAsString);
	this->year = std::stoi(yearAsString);
	if(!validateDate())
		throw("Invalid date!");
}

int Date::getNumberOfDays()
{
	//getDayNbFromDate returns the this->day of the this->year from the current date
	//Output: dayNumber - number
	//		  false - in case of invalid date
	if (validateDate())
		return false;
	int months[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = this->day;
	for (int i = 1; i < this->month; i++)
		sum += months[i];
	return sum + (isLeapYear(this->year) && this->month > 2);
}

bool Date::validateDate()
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

bool Date::isLeapYear(int year)
{
	//checks if a given this->year has 29 or 28 days in February
	//Input: this->year - positiv integer
	//Output: True if given this->year is a leap one
	//		  False otherwise
	return ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0);
}
