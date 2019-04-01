#include "Controller_Admin.h"

void Controller_Admin::addRecord(const std::string & title, const std::string & location, const Date & timeOfCreation, const int numberOfAccessings, const std::string & footagePreview)
{
	auto newRecord = SecurityRecord(title, location, timeOfCreation, numberOfAccessings, footagePreview);
	recordsRepository.addRecord(newRecord);
}

void Controller_Admin::addRecord(SecurityRecord & newRecord)
{
	recordsRepository.addRecord(newRecord);
}

void Controller_Admin::deleteRecord(std::string & title)
{
	auto newRecord = SecurityRecord(title, "", Date(), 0, "");
	recordsRepository.deleteRecord(newRecord);
}

void Controller_Admin::deleteRecord(SecurityRecord & recordToDelete)
{
	recordsRepository.deleteRecord(recordToDelete);
}

void Controller_Admin::updateRecord(const std::string & title, const std::string & newLocation, const Date & newTimeOfCreation, const int newNumberOfAccessings, const std::string & newFootagePreview)
{
	auto newRecord = SecurityRecord(title, newLocation, newTimeOfCreation, newNumberOfAccessings, newFootagePreview);
	recordsRepository.updateRecord(newRecord);
}


void Controller_Admin::updateRecord(SecurityRecord & recordToUpdate)
{
	recordsRepository.updateRecord(recordToUpdate);
}

DynamicArray<SecurityRecord> Controller_Admin::getRecords()
{
	return recordsRepository.getRecords();
}
