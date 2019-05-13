#pragma once
#include <vector>
#include "../domain/SecurityRecord.h"
class Repository
{
protected:
	std::vector<SecurityRecord> listOfSecurityRecords;
public:
	Repository() {}
	Repository(const Repository & copyOfRepository) { this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords; }
	bool addRecord(const SecurityRecord& newRecord);
	bool deleteRecord(SecurityRecord& newRecord);
	bool updateRecord(SecurityRecord& recordToDelete);
	int findRecord(const SecurityRecord& recordToFind);
	std::vector<SecurityRecord>& getRecords();

	void operator=(const Repository& repositoryToAssign) {
		this->listOfSecurityRecords = repositoryToAssign.listOfSecurityRecords;
	}
	virtual bool loadFromFile() { return true; };
	virtual bool saveInFile() { return true; };
};

