#include "Repository.h"
#include "../exeptions/existingTitleException.h"
#include <algorithm>

bool Repository::addRecord(const SecurityRecord& newRecord)
{
	if(this->findRecord(newRecord) != -1)
		throw ExistingTitleException();
	listOfSecurityRecords.push_back(newRecord);
	return true;
}

bool Repository::deleteRecord(SecurityRecord& newRecord)
{
	int recordingsPosition = this->findRecord(newRecord);
	if (recordingsPosition == -1)
		throw ExistingTitleException();
	listOfSecurityRecords.erase(listOfSecurityRecords.begin()+recordingsPosition);
	return true;
}

bool Repository::updateRecord(SecurityRecord & recordToUpdate)
{
	int recordingsPosition = this->findRecord(recordToUpdate);
	if (recordingsPosition == -1)
		throw ExistingTitleException();
	listOfSecurityRecords[recordingsPosition] = recordToUpdate;
	return true;
}

int Repository::findRecord(const SecurityRecord & recordToFind)
{
	auto iteratorOfGivenRecord = std::find(listOfSecurityRecords.begin(), listOfSecurityRecords.end(), recordToFind);
	if (iteratorOfGivenRecord == this->listOfSecurityRecords.end())
		return -1;
	return std::distance(this->listOfSecurityRecords.begin(), iteratorOfGivenRecord);
}

std::vector<SecurityRecord>& Repository::getRecords()
{
	return this->listOfSecurityRecords;
}

