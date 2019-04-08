#pragma once
#include "Controller.h"
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>

class UI
{
private:
	Controller controller;
public:
	UI() {};
	void start();
private:
void printAdminMenu();
void addRecord(std::vector<std::string> command);
void updateRecord(std::vector<std::string> command);
void deleteRecord(std::vector<std::string> command);
void listElements();
void nextRecord();
void saveByTitle(std::vector<std::string> command);
void listByLocationAndAccessingTimes(std::vector<std::string> command);
void userList();
void printList(DynamicArray<SecurityRecord>& recordsToPrint);
static inline void removeSpacesBeforeAndAfterAString(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
		}));
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}
std::vector<std::string> splitCommand(std::string& command);
};

