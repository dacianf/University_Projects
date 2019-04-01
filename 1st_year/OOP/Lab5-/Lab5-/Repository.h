#pragma once
#include "DynamicArray.h"
#include "SecurityRecord.h"
class Repository
{
private:
	DynamicArray<SecurityRecord> listOfSecurityRecords;
public:
	void addRecord(SecurityRecord& newRecord);
	bool deleteRecord(SecurityRecord& newRecord);
	bool updateRecord(SecurityRecord& recordToDelete);
	DynamicArray<SecurityRecord> getRecords();
};

