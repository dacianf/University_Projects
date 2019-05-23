#pragma once
#include <vector>
#include "../domain/SecurityRecord.h"
class Repository
{
protected:
	std::vector<SecurityRecord> listOfSecurityRecords;
	std::string path;
public:
	Repository() {}
	Repository(const Repository & copyOfRepository) { this->listOfSecurityRecords = copyOfRepository.listOfSecurityRecords; }
	virtual bool addRecord(const SecurityRecord& newRecord);
	virtual bool deleteRecord(SecurityRecord& newRecord);
	virtual bool updateRecord(SecurityRecord& recordToDelete);
	virtual int findRecord(const SecurityRecord& recordToFind);
	virtual void setPath(const std::string path) {};
	std::vector<SecurityRecord>& getRecords();

	void operator=(const Repository& repositoryToAssign) {
		this->listOfSecurityRecords = repositoryToAssign.listOfSecurityRecords;
	}
	virtual bool loadRepository() { return true; };
	virtual bool saveRepository() { return true; };
};

