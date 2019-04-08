#pragma once
#include "Repository.h"
class Controller_Admin
{
private:
	Repository recordsRepository;
public:
	Controller_Admin() {}
	void addRecord(const std::string &title, const std::string &location, const Date &timeOfCreation, const int numberOfAccessings, const std::string &footagePreview);
	void addRecord(SecurityRecord& newRecord);

	void deleteRecord(std::string& title);
	void deleteRecord(SecurityRecord& recordToDelete);

	void updateRecord(const std::string &title, const std::string &newLocation, const Date &newTimeOfCreation, const int newNumberOfAccessings, const std::string &newFootagePreview);
	void updateRecord(SecurityRecord& recordToUpdate);

	DynamicArray<SecurityRecord>& getRecords();
	Repository getCopyOfRepository();
};

