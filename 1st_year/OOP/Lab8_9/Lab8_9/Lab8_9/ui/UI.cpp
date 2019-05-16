#include "UI.h"
#include <Windows.h>
#include "../exeptions/invalidCommandException.h"


void UI::start()
{
	std::cout << "Please select mode:\n\tFor admin type: mode A\n\tFor user type: menu B\nIf you want to exit type:\n\texit\n"
		<<"If you want to load/save from/into a file type:\n\tfileLocation [path]\n"<<
		"For saving the reports you want, type:\n\tmylistLocation [path]\n";
	std::string command;
	std::vector<std::string> commandsParameters;
	int mode = -1;
	while (true) {
		try {
			std::cout << "\n>";
			std::getline(std::cin, command);
			if (command.compare("exit") == 0) {
				if(this->controller != NULL)
					this->controller->saveRecordsInFile();
				return;
			}
			removeSpacesBeforeAndAfterAString(command);
			commandsParameters = this->splitCommand(command);
			if (mode == 0){
				if (commandsParameters[0].compare("add") == 0 && commandsParameters.size() == 6) {
					this->addRecord(commandsParameters);
				}
				else if (commandsParameters[0].compare("update") == 0 && commandsParameters.size() == 6)
					this->updateRecord(commandsParameters);
				else if (commandsParameters[0].compare("list") == 0 && commandsParameters.size() == 1)
					this->listElements();
				else if (commandsParameters[0].compare("delete") == 0 && commandsParameters.size() == 2)
					this->deleteRecord(commandsParameters);
				else if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("B") == 0)
					std::cout << "Welcome in user mode!", mode = 1;
				else std::cout << "Invalid command!";
			}
			else if (mode == 1)
			{
				if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("A") == 0)
					std::cout << "Welcome in admin mode!", mode = 0;
				else if (commandsParameters[0].compare("next") == 0 and commandsParameters.size() == 1) {
					this->nextRecord();
				}
				else if (commandsParameters[0].compare("save") == 0 and commandsParameters.size() == 2) {
					this->saveByTitle(commandsParameters);
				}
				else if (commandsParameters[0].compare("list") == 0 and commandsParameters.size() == 3) {
					this->listByLocationAndAccessingTimes(commandsParameters);
				}
				else if (commandsParameters[0].compare("mylist") == 0 and commandsParameters.size() == 1) {
					if(this->savedLocation.size() == 0)
						this->userList();
					else this->openSaved();
				}
				else std::cout << "Incorrect command!";
			}
			else {
				if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("A") == 0) {
					this->printAdminMenu();
					mode = 0;
					this->createController();
				}
				else if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("B") == 0) {
					std::cout << "Welcome in user mode!", mode = 1;
					this->createController();
				}
				else if (commandsParameters[0] == "fileLocation" and commandsParameters.size() == 2) {
					this->recordsLocation = commandsParameters[1];
				}
				else if (commandsParameters[0] == "mylistLocation" and commandsParameters.size() == 2) {
					this->savedLocation = commandsParameters[1];
				}
				else std::cout << "Incorrect command!";
			}
		}
		catch (std::exception e)
		{
			std::cout << e.what();
		}
	}
}

void UI::openSaved()
{
	ShellExecute(NULL, "open", this->savedLocation.c_str(), NULL, NULL, SW_SHOWDEFAULT);
}

void UI::createController()
{
	if (this->recordsLocation == "" and this->savedLocation == "") {
		this->controller = new Controller();
	}
	else if (this->recordsLocation != "" and this->savedLocation == "") {
		Repository* records;
		if(this->recordsLocation == "db")
			records = new DB_Repository(this->recordsLocation);
		else records = new File_Repository(this->recordsLocation);
		auto savedRecords = new Repository();
		this->controller = new Controller(records, savedRecords);
	}
	else if (this->recordsLocation == "" and this->savedLocation != "") {
		auto records = new Repository();
		auto savedRecords = new File_Repository(this->savedLocation);
		this->controller = new Controller(records, savedRecords);
	}
	else {
		Repository* records;
		if (this->recordsLocation == "db")
			records = new DB_Repository(this->recordsLocation);
		else records = new File_Repository(this->recordsLocation);
		auto savedRecords = new File_Repository(this->savedLocation);
		this->controller = new Controller(records, savedRecords);
	}
}

void UI::printAdminMenu()
{
	std::string menuString = { "\t  Welcome to records management!!!\n\n" };
	menuString += "for adding a record please type:\n\t\'add title, location, timeOfCreation, timesAccessed, footagePreview\'\n";
	menuString += "for deleting a record please type:\n\t\'delete title\'\n";
	menuString += "for updating a record please type:\n\t\'update title, newLocation, newTime, newTimesAccessed, newFootagePreview\'\n";
	menuString += "for printing the records please type:\n\t\'list\'\n";
	menuString += "for exit please type:\n\t\'exit\'\n\n";
	std::cout << menuString;
}

void UI::addRecord(std::vector<std::string> command)
{
	if (command.size() != 6)
		throw InvalidCommandException("Invalid add command");
	auto d = Date(command[3]);
	auto r = stoi(command[4]);
	this->controller->addRecord(command[1], command[2], d, r, command[5]);
}

void UI::updateRecord(std::vector<std::string> command)
{
	if (command.size() != 6)
		throw InvalidCommandException("Command update invalid!");
	this->controller->updateRecord(command[1], command[2], Date(command[3]), atoi(command[4].c_str()), command[5]);
}

void UI::deleteRecord(std::vector<std::string> command)
{
	if (command.size() != 2)
		throw InvalidCommandException("Command delete invalid!");
	this->controller->deleteRecord(command[1]);
}

void UI::listElements()
{
	this->printList(this->controller->getRecords());
}

void UI::nextRecord()
{
	std::cout << this->controller->nextRecord();
}

void UI::saveByTitle(std::vector<std::string> command)
{
	this->controller->saveTitle(command[1]);
}

void UI::listByLocationAndAccessingTimes(std::vector<std::string> command)
{
	auto recordsToPrint = this->controller->getSavedRecordsByLocationAndMaximumNumberOfAccessings(command[1], stoi(command[2]));
	this->printList(recordsToPrint);
}

void UI::userList()
{
	this->printList(this->controller->getSavedRecords());
}

void UI::printList(std::vector<SecurityRecord>& recordsToPrint) {
	if (recordsToPrint.size() != 0)
		for (auto record : recordsToPrint)
			std::cout << record << "\n";
	else std::cout << "No item in the list!";
}

std::vector<std::string> UI::splitCommand(std::string & command)
{
	int firstSpace = -1;
	for (int i = 0; i < command.size(); i++) {
		if (command[i] == ' ')
			firstSpace = i, i = command.size();
	}
	//add matrix, deck d floor 7, 7-10-2010, 5, da.mp4
	std::istringstream commandAsStream(command.substr(firstSpace + 1));
	std::string commandParameter;
	std::vector<std::string> dateParameters;
	if (firstSpace != -1)
		dateParameters.push_back(command.substr(0, firstSpace));
	else{
		dateParameters.push_back(command);
		return dateParameters;
	}
	int index = { 0 };
	while (std::getline(commandAsStream, commandParameter, ','))
		dateParameters.push_back(commandParameter);
	for (auto& parameter : dateParameters) {
		removeSpacesBeforeAndAfterAString(parameter);
	}
	return dateParameters;
}

