#include "TestEverything.h"
#include <assert.h>

void TestEverything::testAll()
{
	this->testControllerWithFakeRepo();

	this->createRecord_badInput();
	this->createRecord_goodInput();

	this->createRepository_goodInput();

	this->createDate_badInput();
	this->createDate_goodInput();

	this->addRecordInRepository_badInput();
	this->addRecordInRepository_goodInput();	
	this->deleteRecordFromRepository_badInput();
	this->deleteRecordFromRepository_goodInput();
	this->updateRecordFromRepository_badInput();
	this->updateRecordFromRepository_goodInput();
	this->listRecordsFromRepository_goodInput();
	
	//this->createInMemoryController();
	this->createInFileController();

	this->addRecordInController_byArguments_goodInput();
	this->addRecordInController_byArguments_badInput();
	this->addRecordInController_byRecord_goodInput();
	this->addRecordInController_byRecord_badInput();

	this->deleteRecordFromController_byArguments_goodInput();
	this->deleteRecordFromController_byArguments_badInput();
	this->deleteRecordFromController_byRecord_goodInput();
	this->deleteRecordFromController_byRecord_badInput();

	this->updateRecordFromController_byArguments_goodInput();
	this->updateRecordFromController_byArguments_badInput();
	this->updateRecordFromController_byRecord_goodInput();
	this->updateRecordFromController_byRecord_badInput();

	this->saveTitleFromController_goodInput();
	this->saveTitleFromController_badInput();

	this->nextRecord_goodInput();
	this->nextRecord_badInput();

	this->getSavedRecords_goodInput();
	this->getSavedRecords_badInput();

	this->getAllRecords_goodInput();
	this->getAllRecords_badInput();

	this->filterByLocationAndAccessing_goodInput();
	this->filterByLocationAndAccessing_badInput();

	this->recordToString();
	this->dateToString();

	this->saveInFile();
	this->loadInFile();
}

void TestEverything::testControllerWithFakeRepo()
{
	auto recordsRecords = new fakeRepository();
	auto saveRecords = new fakeRepository();
	auto controller = new Controller(recordsRecords, saveRecords);
	auto newRecordWithAllMembersInitialized = SecurityRecord("Ion", "Second floor", Date("5-10-20"), 13, "record.mp4");
	assert(controller->addRecord(newRecordWithAllMembersInitialized));
	assert(controller->deleteRecord(newRecordWithAllMembersInitialized));
	assert(controller->updateRecord(newRecordWithAllMembersInitialized));
}

void TestEverything::createRecord_goodInput()
{
	try {
		auto newEmptyRecord = SecurityRecord();
		auto newRecordWithJustTitle = SecurityRecord("Matrix");
		auto newRecordWithAllMembersInitialized = SecurityRecord("Ion", "Second floor", Date("5-10-20"), 13, "record.mp4");
		auto copyOfRecord = newEmptyRecord;
		assert(true);
	}
	catch (...) {
		assert(false);
	}
}

void TestEverything::createRecord_badInput()
{
	try {
		auto recordWithInvalidAccessings = SecurityRecord("Ion", "Second floor", Date("5-10-20"), 0, "record.mp4");
		assert(false);
	}
	catch( ... ){
		assert(true);
	}
}

void TestEverything::createDate_goodInput()
{
	try {
		auto dateEmpty = Date();
		auto dateCreatedWithInt = Date(10,4,2010);
		auto dateCreatedWithString = Date("5-10-2010");
		assert(true);
	}
	catch (...) {
		assert(false);
	}
}

void TestEverything::createDate_badInput()
{
	try {
		auto dateWithBadDayAndMonth = Date("13-32-2019");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::createRepository_goodInput()
{
	try {
		auto newRepository = Repository();
		auto copyOfRepository = newRepository;
		assert(true);
	}
	catch (...) {
		assert(false);
	}
}

void TestEverything::addRecordInRepository_goodInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	assert(newRepository.addRecord(newRecord) == true);
}

void TestEverything::addRecordInRepository_badInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	auto copyOfNewRecord = newRecord;
	newRepository.addRecord(newRecord);
	try {
		newRepository.addRecord(copyOfNewRecord);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::deleteRecordFromRepository_goodInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	newRepository.addRecord(newRecord);
	assert(newRepository.deleteRecord(newRecord) == true);
}

void TestEverything::deleteRecordFromRepository_badInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	try {
		newRepository.deleteRecord(newRecord);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::updateRecordFromRepository_goodInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	newRepository.addRecord(newRecord);
	auto updateOfNewRecord = newRecord;
	updateOfNewRecord.setLocation("Cluj");
	updateOfNewRecord.setFootagePreview("movie.mp4");
	assert(newRepository.updateRecord(updateOfNewRecord) == true);
}

void TestEverything::updateRecordFromRepository_badInput()
{
	auto newRepository = Repository();
	auto newRecord = SecurityRecord();
	try {
		newRepository.updateRecord(newRecord);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::listRecordsFromRepository_goodInput()
{
	auto newRepository = Repository();
	auto newEmptyRecord = SecurityRecord();
	auto recordWithTitle = SecurityRecord("Titlu");
	newRepository.addRecord(newEmptyRecord);
	newRepository.addRecord(recordWithTitle);
	auto records = newRepository.getRecords();
	assert(records.size() == 2);
}

//void TestEverything::createInMemoryController()
//{
//	try {
//		//auto memoryController = Controller();
//		Controller memoryController;
//		auto copyController = memoryController;
//		// copyController = memoryController;
//	}
//	catch (...) {
//		assert(false);
//	}
//}

void TestEverything::createInFileController()
{
	try {
		auto recordsRepository = new File_Repository("testFile.txt");
		auto savedRepository = new Repository();
		auto fileController = Controller(recordsRepository, savedRepository);
		assert(true);
	}
	catch (...) {
		assert(false);
	}
}

void TestEverything::addRecordInController_byArguments_goodInput()
{
	Controller controller;
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	assert(controller.addRecord("Titlu2", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	assert(controller.getRecords().size() == 2);
}

void TestEverything::addRecordInController_byArguments_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	try {
		controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
		assert(false);
	}
	catch (...) {
		assert(true);
	}

}

void TestEverything::addRecordInController_byRecord_goodInput()
{
	auto controller = Controller();
	auto record = SecurityRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
	assert(controller.addRecord(record) == true);

}

void TestEverything::addRecordInController_byRecord_badInput()
{
	auto controller = Controller();
	auto record = SecurityRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
	assert(controller.addRecord(record) == true);
	try {
		controller.addRecord(record);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::deleteRecordFromController_byArguments_goodInput()
{
	auto controller = Controller();
	auto record = SecurityRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord(record);
	auto title = std::string("Titlu");
	assert(controller.deleteRecord(title) == true);
}

void TestEverything::deleteRecordFromController_byArguments_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	try {
		auto title = std::string("Titluuu");
		controller.deleteRecord(title);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::deleteRecordFromController_byRecord_goodInput()
{
	auto controller = Controller();
	auto record = SecurityRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord(record);
	assert(controller.deleteRecord(record) == true);
}

void TestEverything::deleteRecordFromController_byRecord_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	try {
		auto title = SecurityRecord("Its Not OK");
		controller.deleteRecord(title);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::updateRecordFromController_byArguments_goodInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	assert(controller.updateRecord("Titlu", "Locatie2", Date("1-1-1"), 1, "film.mp4") == true);
}

void TestEverything::updateRecordFromController_byArguments_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	try {
		controller.updateRecord("Titluuu", "Locatie", Date("1-1-1"), 1, "film.mp4");
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::updateRecordFromController_byRecord_goodInput()
{
	auto controller = Controller();
	auto record = SecurityRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4");
	auto updatedRecord = SecurityRecord("Titlu", "Locatie2", Date("2-1-1"), 1, "film.mp4");
	controller.addRecord(record);
	assert(controller.updateRecord(updatedRecord) == true);
}

void TestEverything::updateRecordFromController_byRecord_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	try {
		auto title = SecurityRecord("Its Not OK");
		controller.updateRecord(title);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::saveTitleFromController_goodInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
	auto title = std::string("Titlu");
	assert(controller.saveTitle(title) == true);
}

void TestEverything::saveTitleFromController_badInput()
{
	try {
		auto controller = Controller();
		assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
		auto title = std::string("Titluuu");
		controller.saveTitle(title);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
	try {
		auto controller = Controller();
		assert(controller.addRecord("Titlu", "Locatie", Date("1-1-1"), 1, "film.mp4") == true);
		auto title = std::string("Titlu");
		controller.saveTitle(title);
		controller.saveTitle(title);
		assert(false);
	}
	catch (...) {
		assert(true);
	}
}

void TestEverything::nextRecord_goodInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4") == true);
	assert(controller.addRecord("Titlu2", "Locatie2", Date("1-1-1"), 2, "film.mp4") == true);
	assert(controller.addRecord("Titlu3", "Locatie3", Date("1-1-1"), 3, "film.mp4") == true);
	auto nextRecord = controller.nextRecord();
	assert(nextRecord.getNumberOfAccessing() == 1);
	assert(nextRecord.getLocation() == "Locatie1");
	assert(nextRecord.getTitle() == "Titlu");
	auto nextRecord2 = controller.nextRecord();
	auto nextRecord3 = controller.nextRecord();
	auto nextRecord4 = controller.nextRecord();
}

void TestEverything::nextRecord_badInput()
{
	auto controller = Controller();
	assert(controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4") == true);
	assert(controller.addRecord("Titlu2", "Locatie2", Date("1-1-1"), 2, "film.mp4") == true);
	assert(controller.addRecord("Titlu3", "Locatie3", Date("1-1-1"), 3, "film.mp4") == true);
	auto nextRecord = controller.nextRecord();
	assert(nextRecord.getNumberOfAccessing() != 2);
	assert(nextRecord.getLocation() != "Locatie2");
	assert(nextRecord.getTitle() != "Titlu2");
}

void TestEverything::getSavedRecords_goodInput()
{
	auto controller = Controller();
	controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord("Titlu2", "Locatie2", Date("1-1-1"), 2, "film.mp4");
	controller.addRecord("Titlu3", "Locatie3", Date("1-1-1"), 3, "film.mp4");
	auto title = std::string("Titlu");
	controller.saveTitle(title);
	auto savedRecords = controller.getSavedRecords();
	assert(savedRecords.size() == 1);
}

void TestEverything::getSavedRecords_badInput()
{
	auto controller = Controller();
	controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	auto savedRecords = controller.getSavedRecords();
	assert(savedRecords.size() == 0);
}

void TestEverything::getAllRecords_goodInput()
{
	auto controller = Controller();
	controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord("Titlu2", "Locatie2", Date("1-1-1"), 2, "film.mp4");
	auto records = controller.getRecords();
	assert(records.size() == 2);
}

void TestEverything::getAllRecords_badInput()
{
	auto controller = Controller();
	auto records = controller.getRecords();
	auto repository = controller.getCopyOfRepository();
	assert(records.size() == repository.getRecords().size());
}

void TestEverything::filterByLocationAndAccessing_goodInput()
{
	auto controller = Controller();
	controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord("Titlu2", "Locatie1", Date("1-1-1"), 2, "film.mp4");
	auto filteredList = controller.getSavedRecordsByLocationAndMaximumNumberOfAccessings("Locatie1", 3);
	assert(filteredList.size() == 2);
}

void TestEverything::filterByLocationAndAccessing_badInput()
{
	auto controller = Controller();
	controller.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	controller.addRecord("Titlu2", "Locatie1", Date("1-1-1"), 2, "film.mp4");
	auto filteredList = controller.getSavedRecordsByLocationAndMaximumNumberOfAccessings("Locatie", 3);
	assert(filteredList.size() == 0);
}

void TestEverything::recordToString()
{
	auto record = SecurityRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	auto stringRecord = record.toString();
}

void TestEverything::dateToString()
{
	auto date = Date();
	auto copyDate = date;
	copyDate.toString();
}

void TestEverything::saveInFile()
{
	auto recordsRepository = new File_Repository("testFile.txt");
	auto savedRepository = new Repository();
	auto fileController = Controller(recordsRepository, savedRepository);
	fileController.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	fileController.addRecord("Titlu2", "Locatie1", Date("11-11-1"), 2, "film.mp4");
	assert(fileController.saveRecordsInFile() == true);
	auto title1 = std::string("Titlu");
	auto title2 = std::string("Titlu2");
	fileController.deleteRecord(title1);
	fileController.deleteRecord(title2);
	assert(fileController.saveRecordsInFile() == true);
}

void TestEverything::loadInFile()
{
	auto recordsRepository = new File_Repository("testFile.txt");
	auto savedRepository = new Repository();
	auto fileController = Controller(recordsRepository, savedRepository);
	fileController.addRecord("Titlu", "Locatie1", Date("1-1-1"), 1, "film.mp4");
	fileController.addRecord("Titlu2", "Locatie1", Date("1-1-1"), 2, "film.mp4");
	assert(fileController.saveRecordsInFile() == true);
	auto title1 = std::string("Titlu");
	auto title2 = std::string("Titlu2");
	fileController.deleteRecord(title1);
	fileController.deleteRecord(title2);
	assert(fileController.loadRecordsFromFile() == true);
	fileController.deleteRecord(title1);
	fileController.deleteRecord(title2);
	assert(fileController.saveRecordsInFile() == true);
}

