#include "UI_Admin.h"


void UI_Admin::start()
{
	this->printMenu();
	std::string command;
	std::vector<std::string> commandsParameters;
	while (true) {
		try {
			std::cout << "\n>";
			std::getline(std::cin, command);
			if (command.compare("exit") == 0)exit(0);
			commandsParameters = this->splitCommand(command);
			if (commandsParameters[0].compare("add") == 0 && commandsParameters.size() == 6)
				this->addRecord(commandsParameters);
			else if (commandsParameters[0].compare("list") == 0 && commandsParameters.size() == 1)
				this->listElements();
		}
		catch (char *er)
		{
			std::cout << er;
		}
	}
}

void UI_Admin::printMenu()
{
	std::string menuString = { "\t  Welcome to records management!!!\n\n" };
	menuString += "for adding a record please type:\n\t\'add title, location, timeOfCreation, timesAccessed, footagePreview\'\n";
	menuString += "for deleting a record please type:\n\t\'delete title\'\n";
	menuString += "for updating a record please type:\n\t\'update title, newLocation, newTime, newTimesAccessed, newFootagePreview\'\n";
	menuString += "for printing the records please type:\n\t\'list\'\n";
	menuString += "for exit please type:\n\t\'exit\'\n\n";
	std::cout << menuString;
}

void UI_Admin::addRecord(std::vector<std::string> command)
{
	if (command.size() != 6)
		throw"Invalid add command";
	this->controllerRecords.addRecord(command[1], command[2], Date(command[3]), atoi(command[4].c_str()), command[5]);
}

void UI_Admin::listElements()
{
	auto signals = controllerRecords.getRecords();
	if(signals.getSize()!=0)
		for (int i = 0; i < signals.getSize(); i++)
			std::cout << signals[i];
	else std::cout << "No item in the list!";
}

std::vector<std::string> UI_Admin::splitCommand(std::string & command)
{
	for (int i = 0; i < command.size(); i++)
		if (command[i] == ',')
			command[i] = ' ';
	std::istringstream commandAsStream(command);
	std::string commandParameter;
	std::vector<std::string> dateParameters;
	int index = { 0 };
	while (std::getline(commandAsStream, commandParameter, ' '))
		dateParameters.push_back(commandParameter);
	return dateParameters;
}
