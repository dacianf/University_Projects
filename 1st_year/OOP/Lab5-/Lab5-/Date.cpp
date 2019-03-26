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
	
	month = std::stoi(monthAsString);
	day = std::stoi(dayAsString);
	year = std::stoi(yearAsString);
	if(!validateDate())
		throw("Invalid date!");
}

int Date::getNumberOfDays()
{
	//getDayNbFromDate returns the day of the year from the current date
	//Output: dayNumber - number
	//		  false - in case of invalid date
	if (validateDate())
		return false;
	int months[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = day;
	for (int i = 1; i < month; i++)
		sum += months[i];
	return sum + (isLeapYear(year) && month > 2);
}

bool Date::validateDate()
{
	//validateDate validates a given date
	//Input: data - date type -- struct which has year, month and day as integers
	//Output: 1 - if the given date is valid
	//		  0 - otherwise
	if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
		return false;
	if (((month % 2 == 1 && month <= 7) || (month % 2 == 0 && month >= 8)) && day > 31)
		return false;
	if (((month % 2 == 0 && month <= 7) || (month % 2 == 1 && month >= 8)) && day > 30)
		return false;
	if (month == 2 && isLeapYear(year) && day > 29)
		return false;
	if (month == 2 && !isLeapYear(year) && day > 28)
		return false;
	return true;
}

bool Date::isLeapYear(int year)
{
	//checks if a given year has 29 or 28 days in February
	//Input: year - positiv integer
	//Output: True if given year is a leap one
	//		  False otherwise
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
