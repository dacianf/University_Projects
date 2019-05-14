#pragma once
#include "../service/Controller.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>

class UI
{
private:
	Controller* controller;
	std::string recordsLocation;
	std::string savedLocation;
public:
	UI() { this->controller = NULL; }
	UI(const UI& copyUI) { *(this->controller) = *(copyUI.controller); }
	void start();
	~UI() { if (this->controller != NULL) delete this->controller; }
private:
void openSaved();
void printAdminMenu();
void createController();
void addRecord(std::vector<std::string> command);
void updateRecord(std::vector<std::string> command);
void deleteRecord(std::vector<std::string> command);
void listElements();
void nextRecord();
void saveByTitle(std::vector<std::string> command);
void listByLocationAndAccessingTimes(std::vector<std::string> command);
void userList();
void printList(std::vector<SecurityRecord>& recordsToPrint);
static inline void removeSpacesBeforeAndAfterAString(std::string &stringToRemoveSpacesFrom) {
	stringToRemoveSpacesFrom.erase(stringToRemoveSpacesFrom.begin(), std::find_if(stringToRemoveSpacesFrom.begin(), stringToRemoveSpacesFrom.end(), [](int characterToCheck) {
		return !std::isspace(characterToCheck);
		}));
	stringToRemoveSpacesFrom.erase(std::find_if(stringToRemoveSpacesFrom.rbegin(), stringToRemoveSpacesFrom.rend(), [](int characterToCheck) {
		return !std::isspace(characterToCheck);
		}).base(), stringToRemoveSpacesFrom.end());
}
std::vector<std::string> splitCommand(std::string& command);
};