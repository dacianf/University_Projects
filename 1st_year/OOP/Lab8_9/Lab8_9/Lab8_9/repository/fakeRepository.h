#pragma once
#include "Repository.h"
class fakeRepository :
	public Repository
{
public:
	fakeRepository() : Repository() {};
	bool addRecord(const SecurityRecord& newRecord) override { return true; };
	bool deleteRecord(SecurityRecord& newRecord) override { return true;};
	bool updateRecord(SecurityRecord& recordToDelete) override { return true;};
	~fakeRepository() {};
};

