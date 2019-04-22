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

	void addRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	void addRecord(SecurityRecord& newRecord);

	void deleteRecord(std::string& title);
	void deleteRecord(SecurityRecord& recordToDelete);

	void updateRecord(const std::string &title, const std::string &newLocation, const Date &newTimeOfCreation, const int newNumberOfAccessings, const std::string &newFootagePreview);
	void updateRecord(SecurityRecord& recordToUpdate);

	SecurityRecord nextRecord();
	bool saveTitle(std::string titleToSave);
	std::vector<SecurityRecord> getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed);
	std::vector<SecurityRecord>& getSavedRecords();
	
	void saveRecordsInFile();
	std::vector<SecurityRecord>& getRecords();
	Repository getCopyOfRepository();

	Controller operator =(Controller assignController) {
		this->indexRecords = assignController.indexRecords;
		this->recordsRepository = assignController.recordsRepository;
		this->savedRecords = assignController.savedRecords;
		return *this;
	}
};

