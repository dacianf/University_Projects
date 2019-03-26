#include "SecurityRecord.h"


SecurityRecord::SecurityRecord(const std::string & title, const std::string & location, const Date & timeOfCreation, const int numberOfAccessings, const std::string & footagePreview)
{
	this->title = title;
	this->id = 0;
	this->location = location;
	this->timeOfCreation = timeOfCreation;
	this->footagePreview = footagePreview;
	this->numberOfAccessings = numberOfAccessings;
}
