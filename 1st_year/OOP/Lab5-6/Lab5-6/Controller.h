#pragma once
#include "Repository.h"
class Controller
{
private:
	Repository recordsRepository;
	Repository savedRecords;
	int indexRecords;
public:
	Controller() { this->indexRecords = 0; }
	void addRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	void addRecord(SecurityRecord& newRecord);

	void deleteRecord(std::string& title);
	void deleteRecord(SecurityRecord& recordToDelete);

	void updateRecord(const std::string &title, const std::string &newLocation, const Date &newTimeOfCreation, const int newNumberOfAccessings, const std::string &newFootagePreview);
	void updateRecord(SecurityRecord& recordToUpdate);

	SecurityRecord nextRecord();
	bool saveTitle(std::string titleToSave);
	DynamicArray<SecurityRecord> getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed);
	DynamicArray<SecurityRecord>& getSavedRecords();

	DynamicArray<SecurityRecord>& getRecords();
	Repository getCopyOfRepository();
};

