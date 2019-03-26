#pragma once
#include "Date.h"

class SecurityRecord
{
private:
	int id;
	std::string title;
	std::string location;
	Date timeOfCreation;
	int numberOfAccessings;
	std::string footagePreview;

public:
	SecurityRecord() :id(0), title(""), location(""), timeOfCreation(Date()), numberOfAccessings(0), footagePreview(""){}
	SecurityRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	
	void setID(int newID) { id = newID; }

};

