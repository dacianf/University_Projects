#pragma once
#include "Date.h"

class SecurityRecord
{
private:
	std::string title;
	std::string location;
	Date timeOfCreation;
	int numberOfAccessings;
	std::string footagePreview;

public:
	SecurityRecord() : title(""), location(""), timeOfCreation(Date()), numberOfAccessings(0), footagePreview(""){}
	SecurityRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	SecurityRecord(const SecurityRecord& copyForRecord);

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

	friend std::ostream& operator<<(std::ostream& recordAsStream, const SecurityRecord& recordToPrint) {
		recordAsStream << recordToPrint.title << "\t" << recordToPrint.location << "\t" <<
			recordToPrint.timeOfCreation << "\t" << recordToPrint.numberOfAccessings << "\t" <<
			recordToPrint.footagePreview;
		return recordAsStream;
	}
	bool operator ==(SecurityRecord& secondRecord)const {
		return (this->title.compare(secondRecord.title) == 0); /*&&
			(this->location.compare(secondRecord.location) == 0) &&
			(this->timeOfCreation == secondRecord.timeOfCreation);*/
	}
	SecurityRecord& operator =(SecurityRecord& secondRecord) {
		this->title = secondRecord.title;
		this->location = secondRecord.location;
		this->timeOfCreation = secondRecord.timeOfCreation;
		this->numberOfAccessings = secondRecord.numberOfAccessings;
		this->footagePreview = secondRecord.footagePreview;
		return *this;
	}
	const std::string toString();
};

