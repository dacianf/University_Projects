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
	auto listOfRecordsFromGivenLocation = std::vector<SecurityRecord>();
	auto recordsArray = this->recordsRepository.getRecords();
	for (int i = 0; i < this->getRecords().size(); i++) {
		if (recordsArray[i].getLocation() == recordsLocation
			and recordsArray[i].getNumberOfAccessing() < timesAccessed)
			listOfRecordsFromGivenLocation.push_back(recordsArray[i]);
	}
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

