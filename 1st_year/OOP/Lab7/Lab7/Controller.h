#pragma once
#include "File_Repository.h"
class Controller
{
private:
	File_Repository recordsRepository;
	File_Repository savedRecords;
	int indexRecords;
public:
	Controller() { this->indexRecords = 0; }
	Controller(std::string recordsFile) {
		this->indexRecords = 0; 
		this->recordsRepository = File_Repository(recordsFile);
	}
	Controller(const Controller& copyController) {
		this->indexRecords = copyController.indexRecords;
		this->recordsRepository = copyController.recordsRepository;
		this->savedRecords = copyController.savedRecords;
	}

	bool addRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	bool addRecord(SecurityRecord& newRecord);

	bool deleteRecord(std::string& title);
	bool deleteRecord(SecurityRecord& recordToDelete);

	bool updateRecord(const std::string &title, const std::string &newLocation, const Date &newTimeOfCreation, const int newNumberOfAccessings, const std::string &newFootagePreview);
	bool updateRecord(SecurityRecord& recordToUpdate);

	SecurityRecord nextRecord();
	bool saveTitle(std::string titleToSave);
	std::vector<SecurityRecord> getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed);
	std::vector<SecurityRecord>& getSavedRecords();
	
	bool saveRecordsInFile();
	bool loadRecordsFromFile();
	std::vector<SecurityRecord>& getRecords();
	Repository getCopyOfRepository();

	Controller operator =(Controller assignController) {
		this->indexRecords = assignController.indexRecords;
		this->recordsRepository = assignController.recordsRepository;
		this->savedRecords = assignController.savedRecords;
		return *this;
	}
};

