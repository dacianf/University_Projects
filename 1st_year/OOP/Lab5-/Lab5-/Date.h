#pragma once
#include <string>

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(): day(1), month(1), year(2000){}
	Date(int givenDay, int givenMonth, int givenYear) : day(givenDay), month(givenMonth), year(givenYear) { validateDate(); }
	Date(std::string& date);

	int getDay() const { return day; }
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getNumberOfDays();

	int operator =(Date secondDate)
	{
		return this->getNumberOfDays == secondDate.getNumberOfDays && this->year == secondDate.year;
	}

	int operator -(Date secondDate)
	{
		return (this->getNumberOfDays + this->year) - (secondDate.getNumberOfDays + secondDate.year);
	}
	int operator +(Date secondDate)
	{
		return (this->getNumberOfDays + this->year) + (secondDate.getNumberOfDays + secondDate.year);
	}
	int operator <(Date secondDate)
	{
		return (this->getNumberOfDays + this->year) - (secondDate.getNumberOfDays + secondDate.year) < 0 ? 1 : 0;
	}
	int operator >(Date secondDate)
	{
		return (this->getNumberOfDays + this->year) - (secondDate.getNumberOfDays + secondDate.year) > 0 ? 1 : 0;
	}
private:
	bool validateDate();
	bool isLeapYear(int year);
};

