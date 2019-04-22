#pragma once
#include "Controller.h"
#include <iostream>
#include <algorithm>
class UI
{
private:
	Controller controller;
public:
	UI() {};
	~UI() {};
	void start();
private:
	void printMenu();
	void printProject(Project& x);
	void printList(std::vector<Project> listToPrint);
	void add();
	void getTotal();
};

