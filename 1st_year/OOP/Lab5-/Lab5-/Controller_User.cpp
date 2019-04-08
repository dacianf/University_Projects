#include "Controller_User.h"


Controller_User::Controller_User(const Controller_User & copyOfControllerUser)
{
	this->indexOfCurrentRecord = copyOfControllerUser.indexOfCurrentRecord;
	this->listOfAllRecords = copyOfControllerUser.listOfAllRecords;
	this->listOfUserRecords = copyOfControllerUser.listOfUserRecords;
}

SecurityRecord Controller_User::nextRecord()
{
	if (this->indexOfCurrentRecord == listOfUserRecords.getRecords().getSize() - 1)
		this->indexOfCurrentRecord = 0;
	return this->listOfAllRecords.getRecords()[this->indexOfCurrentRecord++];
}

bool Controller_User::saveTitle(std::string titleToSave)
{
	if (this->listOfUserRecords.getRecords().findElement(SecurityRecord(titleToSave)))
		throw "This element already exist in your list!";
	int recordToAddIndex = this->listOfAllRecords.getRecords().findElement(SecurityRecord(titleToSave));
	this->listOfUserRecords.addRecord(this->listOfAllRecords.getRecords()[recordToAddIndex]);
	return true;
}

DynamicArray<SecurityRecord> Controller_User::getRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int maximumAccessings)
{
	auto listOfRecordsFromGivenLocation = DynamicArray<SecurityRecord>();
	auto listOfUserRecords = this->getRecords();
	for (int i = 0; i < this->getRecords().getSize(); i++)
		if (listOfUserRecords[i].getLocation().compare(recordsLocation) == 0
			and listOfUserRecords[i].getNumberOfAccessing() < maximumAccessings)
			listOfRecordsFromGivenLocation.addElement(listOfUserRecords[i]);
	return listOfRecordsFromGivenLocation;

}

DynamicArray<SecurityRecord> Controller_User::getRecords()
{
	return this->listOfUserRecords.getRecords();
}

SecurityRecord Controller_User::getCurrentRecord()
{
	return this->listOfAllRecords.getRecords()[this->indexOfCurrentRecord++];
}
