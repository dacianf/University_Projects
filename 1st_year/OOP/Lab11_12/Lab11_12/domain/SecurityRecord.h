#pragma once
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <locale>

class SecurityRecord
{
private:
	std::string title;
	std::string location;
	Date timeOfCreation;
	int numberOfAccessings;
	std::string footagePreview;

public:
	SecurityRecord() : title(" "), location(" "), timeOfCreation(Date()), numberOfAccessings(0), footagePreview(" "){}
	SecurityRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	SecurityRecord(const SecurityRecord& copyForRecord);
	SecurityRecord(const std::string &title);
	~SecurityRecord() {}
	void setTitle(std::string newTitle) { this->title = newTitle; }
	const std::string getTitle() { return this->title; }

	void setLocation(std::string newLocation) { this->location = newLocation; }
	const std::string  getLocation() { return this->location; }

	void setTimeOfCreation(Date newDate) { this->timeOfCreation = newDate; }
	const Date getTimeOfCreation() { return this->timeOfCreation; }

	void setNumberOfAccessing(int newNumberOfAccessings) {this->numberOfAccessings = newNumberOfAccessings;}
	const int getNumberOfAccessing() { return this->numberOfAccessings; }

	void setFootagePreview(std::string newFootagePreview) { this->footagePreview = newFootagePreview; }
	const std::string getFootagePreview() { return this->footagePreview; }

	friend std::ostream& operator << (std::ostream& recordAsStream, const SecurityRecord& recordToPrint) {
		recordAsStream << recordToPrint.title << "," << recordToPrint.location << "," <<
			recordToPrint.timeOfCreation << "," << recordToPrint.numberOfAccessings << "," <<
			recordToPrint.footagePreview;
		return recordAsStream;
	}
	static inline void removeSpacesBeforeAndAfterAString(std::string &stringToRemoveSpacesFrom) {
		stringToRemoveSpacesFrom.erase(stringToRemoveSpacesFrom.begin(), std::find_if(stringToRemoveSpacesFrom.begin(), stringToRemoveSpacesFrom.end(), [](int ch) {
			return !std::isspace(ch);
			}));
		stringToRemoveSpacesFrom.erase(std::find_if(stringToRemoveSpacesFrom.rbegin(), stringToRemoveSpacesFrom.rend(), [](int ch) {
			return !std::isspace(ch);
			}).base(), stringToRemoveSpacesFrom.end());
	}
	friend std::istream& operator >> (std::istream& recordAsStream, SecurityRecord& recordToRead) {
		std::string line = " ";
		std::getline(recordAsStream, line, ',');
		if (recordAsStream.eof() || line=="") return recordAsStream;
		removeSpacesBeforeAndAfterAString(line);
		recordToRead.title = line;

		std::getline(recordAsStream, line, ',');
		removeSpacesBeforeAndAfterAString(line);
		recordToRead.location = line;

		std::getline(recordAsStream, line, ',');
		removeSpacesBeforeAndAfterAString(line);
		if(line != "")
			recordToRead.timeOfCreation = Date(line);

		std::getline(recordAsStream, line, ',');
		removeSpacesBeforeAndAfterAString(line);
		recordToRead.numberOfAccessings = stoi(line);

		std::getline(recordAsStream, line);
		removeSpacesBeforeAndAfterAString(line);
		recordToRead.footagePreview = line;
		return recordAsStream;
	}


	bool operator ==(SecurityRecord secondRecord)const {
		return (this->title.compare(secondRecord.title) == 0); /*&&
			(this->location.compare(secondRecord.location) == 0) &&
			(this->timeOfCreation == secondRecord.timeOfCreation);*/
	}
	SecurityRecord operator =(SecurityRecord secondRecord) {
		this->title = secondRecord.title;
		this->location = secondRecord.location;
		this->timeOfCreation = secondRecord.timeOfCreation;
		this->numberOfAccessings = secondRecord.numberOfAccessings;
		this->footagePreview = secondRecord.footagePreview;
		return *this;
	}
	const std::string toString();
};

