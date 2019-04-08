#include "Controller.h"

void Controller::addRecord(const std::string & title, const std::string & location, const Date & timeOfCreation, const int numberOfAccessings, const std::string & footagePreview)
{
	auto newRecord = new SecurityRecord(title, location, timeOfCreation, numberOfAccessings, footagePreview);
	this->recordsRepository.addRecord(*newRecord);
}

void Controller::addRecord(SecurityRecord & newRecord)
{
	this->recordsRepository.addRecord(newRecord);
}

void Controller::deleteRecord(std::string & title)
{
	auto newRecord = SecurityRecord(title, "", Date(), 0, "");
	this->recordsRepository.deleteRecord(newRecord);
}

void Controller::deleteRecord(SecurityRecord & recordToDelete)
{
	this->recordsRepository.deleteRecord(recordToDelete);
}

void Controller::updateRecord(const std::string & title, const std::string & newLocation, const Date & newTimeOfCreation, const int newNumberOfAccessings, const std::string & newFootagePreview)
{
	auto newRecord = SecurityRecord(title, newLocation, newTimeOfCreation, newNumberOfAccessings, newFootagePreview);
	this->recordsRepository.updateRecord(newRecord);
}


void Controller::updateRecord(SecurityRecord & recordToUpdate)
{
	this->recordsRepository.updateRecord(recordToUpdate);
}

SecurityRecord Controller::nextRecord()
{
	if (this->indexRecords == this->recordsRepository.getRecords().getSize())
		this->indexRecords = 0;
	return this->recordsRepository.getRecords()[this->indexRecords++];
}

bool Controller::saveTitle(std::string titleToSave)
{
	if (this->savedRecords.getRecords().findElement(SecurityRecord(titleToSave)) != -1)
		throw "This element already exist in your list!";
	int recordToAddIndex = this->recordsRepository.getRecords().findElement(SecurityRecord(titleToSave));
	this->savedRecords.addRecord(this->recordsRepository.getRecords()[recordToAddIndex]);
	return true;
}

DynamicArray<SecurityRecord> Controller::getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed)
{
	auto listOfRecordsFromGivenLocation = DynamicArray<SecurityRecord>();
	auto recordsArray = this->recordsRepository.getRecords();
	for (int i = 0; i < this->getRecords().getSize(); i++) {
		if (recordsArray[i].getLocation() == recordsLocation
			and recordsArray[i].getNumberOfAccessing() < timesAccessed)
			listOfRecordsFromGivenLocation.addElement(recordsArray[i]);
	}
	return listOfRecordsFromGivenLocation;
}

DynamicArray<SecurityRecord>& Controller::getSavedRecords()
{
	return this->savedRecords.getRecords();
}

DynamicArray<SecurityRecord>& Controller::getRecords()
{
	return this->recordsRepository.getRecords();
}

Repository Controller::getCopyOfRepository()
{
	return Repository(this->recordsRepository);
}

