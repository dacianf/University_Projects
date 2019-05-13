#pragma once
#include "../service/Controller.h"

class TestEverything
{
public:
	void testAll();
	TestEverything() {};
	~TestEverything() {};
private:
	void createRecord_goodInput();
	void createRecord_badInput();

	void createDate_goodInput();
	void createDate_badInput();
	
	void createRepository_goodInput();

	void addRecordInRepository_goodInput();
	void addRecordInRepository_badInput();
	void deleteRecordFromRepository_goodInput();
	void deleteRecordFromRepository_badInput();
	void updateRecordFromRepository_goodInput();
	void updateRecordFromRepository_badInput();
	void listRecordsFromRepository_goodInput();

	//void createInMemoryController();
	void createInFileController();

	void addRecordInController_byArguments_goodInput();
	void addRecordInController_byArguments_badInput();
	void addRecordInController_byRecord_goodInput();
	void addRecordInController_byRecord_badInput();

	void deleteRecordFromController_byArguments_goodInput();
	void deleteRecordFromController_byArguments_badInput();
	void deleteRecordFromController_byRecord_goodInput();
	void deleteRecordFromController_byRecord_badInput();

	void updateRecordFromController_byArguments_goodInput();
	void updateRecordFromController_byArguments_badInput();
	void updateRecordFromController_byRecord_goodInput();
	void updateRecordFromController_byRecord_badInput();

	void saveTitleFromController_goodInput();
	void saveTitleFromController_badInput();

	void nextRecord_goodInput();
	void nextRecord_badInput();

	void getSavedRecords_goodInput();
	void getSavedRecords_badInput();

	void getAllRecords_goodInput();
	void getAllRecords_badInput();

	void filterByLocationAndAccessing_goodInput();
	void filterByLocationAndAccessing_badInput();

	void recordToString();
	void dateToString();

	void saveInFile();
	void loadInFile();
};

