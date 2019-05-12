#pragma once
#include <string>
#include <array>
#include "../exeptions/dateException.h"
#include <sstream>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(): day(1), month(1), year(2000){}
	Date(int givenMonth, int givenDay, int givenYear) : day(givenDay), month(givenMonth), year(givenYear)
		{this->validateDate() == false ? throw DateExeption() :0; }
	Date(const Date& copyForDate);
	Date(const std::string& date);

	int getDay() const { return day; }
	int getYear() const { return year; }
	int getMonth() const { return month; }
	const int getNumberOfDays()
	{
		//getDayNbFromDate returns the this->day of the this->year from the current date
		//Output: dayNumber - number
		//		  false - in case of invalid date
		if (!this->validateDate())
			return false;
		int months[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int sum = this->day;
		for (int i = 1; i < this->month; i++)
			sum += months[i];
		return sum + (isLeapYear(this->year) && this->month > 2);
	}

	Date& operator =(const Date& dateToAssign) {
		this->day = dateToAssign.day;
		this->month = dateToAssign.month;
		this->year = dateToAssign.year;
		return *this;
	}

	int operator <(Date& dateToCompare) {
		if (dateToCompare.year == this->year)
			return this->getNumberOfDays() < dateToCompare.getNumberOfDays();
		return this->getNumberOfDays() < dateToCompare.getNumberOfDays();
	}

	friend std::ostream& operator<<(std::ostream& streamToPrint, const Date& dateToPrint) {
		if (dateToPrint.month < 10)streamToPrint << "0" << dateToPrint.month;
		else streamToPrint << dateToPrint.month;
		streamToPrint << "-";
		if (dateToPrint.day < 10)streamToPrint << "0" << dateToPrint.day;
		else streamToPrint << dateToPrint.day;
		streamToPrint << "-" << dateToPrint.year;
		return streamToPrint;
	}
	friend std::istream& operator >> (std::istream& streamForRead, Date& dateToRead) {
		std::string dateAsString;
		streamForRead >> dateAsString;
		if (dateAsString == "")
			dateToRead = Date();
		else dateToRead = Date(dateAsString);
		return streamForRead;
	}
	bool operator ==(Date& dateToCompare) const {
		return (this->day == dateToCompare.day) &&
			(this->month == dateToCompare.month) &&
			(this->year == dateToCompare.year);
	}

	const std::string toString();

private:
	bool validateDate();
	bool isLeapYear(int year);
};

