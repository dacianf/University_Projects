#pragma once
#include "DynamicArray.h"
#include "SecurityRecord.h"
class Repository
{
private:
	DynamicArray<SecurityRecord> listOfSecurityRecords;
public:
	Repository() {}
	Repository(const Repository & copyOfRepository) { this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords; }
	void addRecord(SecurityRecord& newRecord);
	bool deleteRecord(SecurityRecord& newRecord);
	bool updateRecord(SecurityRecord& recordToDelete);
	DynamicArray<SecurityRecord>& getRecords();

	void operator=(const Repository& repositoryToAssign) {
		this->listOfSecurityRecords = repositoryToAssign.listOfSecurityRecords;
	}
};

