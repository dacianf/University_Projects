#pragma once
#include "Repository.h"
class Controller_User
{
private:
	Repository listOfAllRecords;
	Repository listOfUserRecords;
	int indexOfCurrentRecord;
public:
	Controller_User(){}
	Controller_User(Repository listOfRecords) { this->listOfAllRecords = listOfRecords; this->indexOfCurrentRecord = 0; };
	Controller_User(const Controller_User& copyOfControllerUser);
	SecurityRecord nextRecord();
	bool saveTitle(std::string titleToSave);
	DynamicArray<SecurityRecord> getRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed);
	DynamicArray<SecurityRecord> getRecords();
	SecurityRecord getCurrentRecord();
	void operator =(Controller_User& controllerToAssign) {
		this->indexOfCurrentRecord = controllerToAssign.indexOfCurrentRecord;
		this->listOfAllRecords = controllerToAssign.listOfAllRecords;
		this->listOfUserRecords = controllerToAssign.listOfUserRecords;
	}
};

