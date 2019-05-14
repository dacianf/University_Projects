#include "Controller.h"
#include "../exeptions/serviceExeption.h"

bool Controller::addRecord(const std::string & title, const std::string & location, const Date & timeOfCreation, const int numberOfAccessings, const std::string & footagePreview)
{
	SecurityRecord newRecord(title, location, timeOfCreation, numberOfAccessings, footagePreview);
	return recordsRepository->addRecord(newRecord);
}

bool Controller::addRecord(SecurityRecord & newRecord)
{
	return this->recordsRepository->addRecord(newRecord);
}

bool Controller::deleteRecord(std::string & title)
{
	auto newRecord = SecurityRecord(title, "", Date(), 1, "");
	return this->recordsRepository->deleteRecord(newRecord);
}

bool Controller::deleteRecord(SecurityRecord & recordToDelete)
{
	return this->recordsRepository->deleteRecord(recordToDelete);
}

bool Controller::updateRecord(const std::string & title, const std::string & newLocation, const Date & newTimeOfCreation, const int newNumberOfAccessings, const std::string & newFootagePreview)
{
	auto newRecord = SecurityRecord(title, newLocation, newTimeOfCreation, newNumberOfAccessings, newFootagePreview);
	return this->recordsRepository->updateRecord(newRecord);
}


bool Controller::updateRecord(SecurityRecord & recordToUpdate)
{
	return this->recordsRepository->updateRecord(recordToUpdate);
}

SecurityRecord Controller::nextRecord()
{
	if (this->indexRecords == this->recordsRepository->getRecords().size())
		this->indexRecords = 0;
	return this->recordsRepository->getRecords()[this->indexRecords++];
}

bool Controller::saveTitle(std::string titleToSave)
{
	auto recordToBeSaved = SecurityRecord(titleToSave);
	if (this->savedRecords->findRecord(recordToBeSaved) != -1)
		throw ServiceExeption("This element already exist in your list!");
	int recordToAddIndex = this->recordsRepository->findRecord(recordToBeSaved);
	if (recordToAddIndex == -1)
		throw ServiceExeption("This record does not exist!");
	this->savedRecords->addRecord(this->recordsRepository->getRecords()[recordToAddIndex]);
	this->savedRecords->saveRepository();
	return true;
}

std::vector<SecurityRecord> Controller::getSavedRecordsByLocationAndMaximumNumberOfAccessings(std::string recordsLocation, int timesAccessed)
{
	auto recordsArray = this->recordsRepository->getRecords();
	auto listOfRecordsFromGivenLocation = std::vector<SecurityRecord>(recordsArray.size());
	auto records = std::copy_if(recordsArray.begin(), recordsArray.end(), listOfRecordsFromGivenLocation.begin(), [recordsLocation, timesAccessed](auto record) {
		return record.getLocation() == recordsLocation && record.getNumberOfAccessing() < timesAccessed;
		});
	listOfRecordsFromGivenLocation.resize(std::distance(listOfRecordsFromGivenLocation.begin(), records));
	return listOfRecordsFromGivenLocation;
}

std::vector<SecurityRecord>& Controller::getSavedRecords()
{
	return this->savedRecords->getRecords();
}

bool Controller::saveRecordsInFile()
{
	return this->recordsRepository->saveRepository();
}

bool Controller::loadRecordsFromFile()
{
	return recordsRepository->loadRepository();
}

std::vector<SecurityRecord>& Controller::getRecords()
{
	return this->recordsRepository->getRecords();
}

Repository Controller::getCopyOfRepository()
{
	return Repository(*this->recordsRepository);
}

