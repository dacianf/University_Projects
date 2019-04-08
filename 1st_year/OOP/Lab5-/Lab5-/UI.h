#pragma once
#include "Controller_Admin.h"
#include "Controller_User.h"
#include "Repository.h"
#include <iostream>
#include <vector>

class UI
{
private:
	Controller_Admin controllerAdminRecords;
	Controller_User controllerUserRecords;
public:
	UI();
	void start();
private:
void printMenu();
void addRecord(std::vector<std::string> command);
void updateRecord(std::vector<std::string> command);
void deleteRecord(std::vector<std::string> command);
void listElements();
std::vector<std::string> splitCommand(std::string& command);
};

