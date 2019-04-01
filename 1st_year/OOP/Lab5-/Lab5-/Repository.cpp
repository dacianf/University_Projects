#include "Repository.h"

void Repository::addRecord(SecurityRecord & newRecord)
{
	if (listOfSecurityRecords.findElement(newRecord) != -1)
		throw "This element already exists in repo!";
	listOfSecurityRecords.addElement(newRecord);
}

bool Repository::deleteRecord(SecurityRecord& newRecord)
{
	int recordingsPosition = listOfSecurityRecords.findElement(newRecord);
	if (recordingsPosition == -1)
		throw "There is no record with the same title in the repo!";
	listOfSecurityRecords.removeFromIndex(recordingsPosition);
	return true;
}

bool Repository::updateRecord(SecurityRecord & recordToUpdate)
{
	int recordingsPosition = listOfSecurityRecords.findElement(recordToUpdate);
	if (recordingsPosition == -1)
		throw "There is no record with the same title in the repo!";
	listOfSecurityRecords[recordingsPosition] = recordToUpdate;
	return true;
}

DynamicArray<SecurityRecord> Repository::getRecords()
{
	return DynamicArray<SecurityRecord>(listOfSecurityRecords);
}

