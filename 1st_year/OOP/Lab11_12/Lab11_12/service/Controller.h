#pragma once
#include "../repository/File_Repository.h"
class Controller
{
private:
	Repository* recordsRepository;
	Repository* savedRecords;
	int indexRecords;
public:
	Controller(Repository* _recordsRepository, Repository* _savedRepository) : recordsRepository(_recordsRepository), savedRecords(_savedRepository), indexRecords(0) {}
	Controller() {
		recordsRepository = new Repository();
		savedRecords = new Repository();
	}
	//Controller(const Controller& copyController) {
	//	indexRecords = copyController.indexRecords;
	//	*recordsRepository = *copyController.recordsRepository;
	//	*savedRecords = *copyController.savedRecords;
	//}
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

	Repository* getCopyOfSavedRepository();

	//Controller operator =(Controller assignController) {
	//	indexRecords = assignController.indexRecords;
	//	*recordsRepository = *assignController.recordsRepository;
	//	*savedRecords = *assignController.savedRecords;
	//	return *this;
	//}
	void setRecordsPath(std::string path);
	void setSavedPath(std::string path);
	~Controller() {
		delete recordsRepository;
		delete savedRecords;
	}
};

