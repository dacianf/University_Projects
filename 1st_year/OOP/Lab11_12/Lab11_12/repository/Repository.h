#pragma once
#include <vector>
#include "UndoRedo.h"
#include "../domain/SecurityRecord.h"
class Repository
{
	friend class UndoRedo;
protected:
	std::vector< SecurityRecord > listOfSecurityRecords;
	std::string path;
	UndoRedo* undoRedo;
public:
	Repository();
	Repository(const Repository & copyOfRepository);
	virtual bool addRecord(const SecurityRecord& newRecord);
	virtual bool deleteRecord(SecurityRecord& newRecord);
	virtual bool updateRecord(SecurityRecord& recordToDelete);
	virtual int findRecord(const SecurityRecord& recordToFind);
	virtual void setPath(const std::string path) {};
	virtual bool undo();
	virtual bool redo();
	std::vector<SecurityRecord>& getRecords();

	void operator=(const Repository& repositoryToAssign) {
		this->listOfSecurityRecords = repositoryToAssign.listOfSecurityRecords;
	}
	virtual bool loadRepository() { return true; };
	virtual bool saveRepository() { return true; };
	~Repository();
};

