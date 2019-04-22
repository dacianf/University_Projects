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
	if (this->indexRecords == this->recordsRepository.getRecords().size())
		this->indexRecords = 0;
	return this->recordsRepository.getRecords()[this->indexRecords++];
}

bool Controller::saveTitle(std::string titleToSave)
{
	auto recordToBeSaved = SecurityRecord(titleToSave);
	if (this->savedRecords.findRecord(recordToBeSaved) != -1)
		throw "This element already exist in your list!";
	int recordToAddIndex = this->recordsRepository.findRecord(recordToBeSaved);
	if (recordToAddIndex == -1)
		throw "This record does not exist!";
	this->savedRecords.addRecord(this->recordsRepository.getRecords()[recordToAddIndex]);
	return true;
}

std::vector<SecurityRecord> Controller::getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed)
{
	auto recordsArray = this->recordsRepository.getRecords();
	auto listOfRecordsFromGivenLocation = std::vector<SecurityRecord>(recordsArray.size());
	auto records = std::copy_if(recordsArray.begin(), recordsArray.end(), listOfRecordsFromGivenLocation.begin(), [recordsLocation, timesAccessed](auto record) {
		return record.getLocation() == recordsLocation and record.getNumberOfAccessing() < timesAccessed;
		});
	listOfRecordsFromGivenLocation.resize(std::distance(listOfRecordsFromGivenLocation.begin(), records));
	return listOfRecordsFromGivenLocation;
}

std::vector<SecurityRecord>& Controller::getSavedRecords()
{
	return this->savedRecords.getRecords();
}

void Controller::saveRecordsInFile()
{
	this->recordsRepository.saveInFile();
}

std::vector<SecurityRecord>& Controller::getRecords()
{
	return this->recordsRepository.getRecords();
}

Repository Controller::getCopyOfRepository()
{
	return Repository(this->recordsRepository);
}

