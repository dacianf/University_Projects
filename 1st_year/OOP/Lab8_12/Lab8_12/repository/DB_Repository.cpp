#define _CRT_SECURE_NO_WARNINGS
#include "DB_Repository.h"


static int callback(void *arrayOfRecords, int numberOfArguments, char **arrayOfArguments, char **columnsName) {
	auto* _securityRecordsArray = (std::vector<SecurityRecord>*)arrayOfRecords;
	SecurityRecord _securityRecord{};

	_securityRecord.setTitle(arrayOfArguments[1]);
	_securityRecord.setLocation(arrayOfArguments[2]);
	_securityRecord.setTimeOfCreation(Date(arrayOfArguments[3]));
	_securityRecord.setNumberOfAccessing(std::stoi(arrayOfArguments[4]));
	_securityRecord.setFootagePreview(arrayOfArguments[5]);

	_securityRecordsArray->push_back(_securityRecord);
	return 0;
}

bool DB_Repository::loadRepository()
{
	const char* sqlQuery = "SELECT * FROM RECORDS";
	char* error = nullptr;
	sqlite3_exec(this->database, sqlQuery, callback, (void*)&this->listOfSecurityRecords, &error);
	return (error == nullptr) ? true : false;
}

bool DB_Repository::saveRepository()
{
	char* error = nullptr;
	const char* dropTableSql = "DELETE FROM RECORDS";
	const char* cleanUnsedSpace = "VACUUM";
	sqlite3_exec(this->database, dropTableSql, nullptr, nullptr, &error);
	sqlite3_exec(this->database, cleanUnsedSpace, nullptr, nullptr, &error);

	for (int idx = 0; idx < this->listOfSecurityRecords.size(); idx++) {
		std::stringstream ss;
		SecurityRecord newSecurityRecord = this->listOfSecurityRecords[idx];
		ss << "INSERT INTO RECORDS VALUES (" << idx << ",'" << newSecurityRecord.getTitle()
			<< "','" << newSecurityRecord.getLocation() << "','" << newSecurityRecord.getTimeOfCreation() << "',"
			<< newSecurityRecord.getNumberOfAccessing() << ",'" << newSecurityRecord.getFootagePreview() << "')";
		sqlite3_exec(this->database, ss.str().c_str(), nullptr, nullptr, &error);
	}
	return (error == nullptr) ? true : false;
}

DB_Repository::DB_Repository(const std::string& path)
{
	std::stringstream pathAsString;
	pathAsString << "./data/" << "records_db.sqlite";
	this->fileLocation = pathAsString.str();
	int error = sqlite3_open(this->fileLocation.c_str(), &this->database);
	if (!error) this->loadRepository();
	else throw std::exception("Could not connect to database!");
}

DB_Repository::~DB_Repository()
{
	this->saveRepository();
	sqlite3_close(this->database);
}
