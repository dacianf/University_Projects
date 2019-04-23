#include "SecurityRecord.h"
#include <iostream>

using namespace std;

SecurityRecord::SecurityRecord(const std::string & title, const std::string & location, const Date & timeOfCreation, const int accessingsNumber, const std::string & footagePreview)
{
	if (accessingsNumber < 1)
		throw std::exception("Invalid accessings number!");
	this->title = title;
	this->location = location;
	this->timeOfCreation = timeOfCreation;
	this->footagePreview = footagePreview;
	this->numberOfAccessings = accessingsNumber;
}

SecurityRecord::SecurityRecord(const SecurityRecord & copyForRecord)
{
	//copy constructor
	this->title = copyForRecord.title;
	this->location = copyForRecord.location;
	this->timeOfCreation = copyForRecord.timeOfCreation;
	this->footagePreview = copyForRecord.footagePreview;
	this->numberOfAccessings = copyForRecord.numberOfAccessings;
}

SecurityRecord::SecurityRecord(const std::string & title)
{
	SecurityRecord();
	this->title = title;
}


const std::string SecurityRecord::toString()
{
	std::ostringstream recordAsStream;
	recordAsStream << *this;
	std::string stringToPrint = recordAsStream.str();
	return stringToPrint;
}
