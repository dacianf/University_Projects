#pragma once
#include <vector>
#include "SecurityRecord.h"
class Repository
{
protected:
	std::vector<SecurityRecord> listOfSecurityRecords;
public:
	Repository() {}
	Repository(const Repository & copyOfRepository) { this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords; }
	bool addRecord(SecurityRecord& newRecord);
	bool deleteRecord(SecurityRecord& newRecord);
	bool updateRecord(SecurityRecord& recordToDelete);
	int findRecord(SecurityRecord& recordToFind);
	std::vector<SecurityRecord>& getRecords();

	void operator=(const Repository& repositoryToAssign) {
		this->listOfSecurityRecords = repositoryToAssign.listOfSecurityRecords;
	}
};

