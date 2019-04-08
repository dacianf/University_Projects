#include "UI.h"


UI::UI() : controllerUserRecords(Controller_User(controllerAdminRecords.getCopyOfRepository())) {};

void UI::start()
{
	std::cout << "Please select mode:\n\tFor admin type: mode A\n\tFor user type: menu B\n";
	std::string command;
	std::vector<std::string> commandsParameters;
	int mode = -1;
	//auto x = SecurityRecord("Dibu", "mmc", Date(1, 1, 1), 2, "da.mp3");
	//this->controllerRecords.addRecord(x);
	while (true) {
		try {
			std::cout << "\n>";
			std::getline(std::cin, command);
			if (command.compare("exit") == 0)
				exit(0);
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
				if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("B") == 0)
					std::cout << "Welcome in user mode!", mode = 1;
				else if (commandsParameters[0].compare("next") == 0 and commandsParameters.size() == 1) {

				}
				else if (commandsParameters[0].compare("save") == 0 and commandsParameters.size() == 2) {

				}
				else if (commandsParameters[0].compare("list") == 0 and commandsParameters.size() == 3) {

				}
				else if (commandsParameters[0].compare("mylist") == 0 and commandsParameters.size() == 1) {

				}
			}
			if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("A") == 0)
				this->printMenu(), mode = 0;
			else if (commandsParameters[0].compare("mode") == 0 and commandsParameters[1].compare("B") == 0)
				std::cout << "Welcome in user mode!", mode = 1;
		}
		catch (const char *error)
		{
			std::cout << error;
		}
	}
}

void UI::printMenu()
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
		throw"Invalid add command";
	auto d = Date(command[3]);
	auto r = stoi(command[4]);
	this->controllerAdminRecords.addRecord(command[1], command[2], d, r, command[5]);
}

void UI::updateRecord(std::vector<std::string> command)
{
	if (command.size() != 6)
		throw"Command update invalid!";
	controllerAdminRecords.updateRecord(command[1], command[2], Date(command[3]), atoi(command[4].c_str()), command[5]);
}

void UI::deleteRecord(std::vector<std::string> command)
{
	if (command.size() != 2)
		throw"Command delete invalid!";
	controllerAdminRecords.deleteRecord(command[1]);
}

void UI::listElements()
{
	DynamicArray<SecurityRecord>& signals = controllerAdminRecords.getRecords();
	if (signals.getSize() != 0)
		for (int i = 0; i < signals.getSize(); i++)
			std::cout << signals[i] << "\n";
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
	return dateParameters;
}
