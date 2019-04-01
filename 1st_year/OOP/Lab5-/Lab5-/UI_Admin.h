#pragma once
#include "Controller_Admin.h"
#include "Repository.h"
#include <iostream>
#include <vector>

class UI_Admin
{
private:
	Repository recordsRepo;
	Controller_Admin controllerRecords;
public:
	UI_Admin() { this->controllerRecords = Controller_Admin(recordsRepo); }

	void start();
private:
void printMenu();
void addRecord(std::vector<std::string> command);
void updateRecord(std::vector<std::string> command);
void deleteRecord(std::vector<std::string> command);
void listElements();
std::vector<std::string> splitCommand(std::string& command);
};

