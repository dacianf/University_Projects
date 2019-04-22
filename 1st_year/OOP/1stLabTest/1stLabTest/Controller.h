#pragma once
#include "Repo.h"
class Controller
{
private:
	Repo repositoryOfProjects;
public:
	Controller() {};
	~Controller() {};
	
	bool addProject(std::string name, std::string sector, std::string date, int quantity, bool isDone);
	/*add project into repo
		Input: name - string
			   sector - string
			   date - string
			   quantity - int
			   isDone - bool
		Output: true - if project was added
				false - otherwise
	*/
	
	std::vector<Project> getAll();
	int getSize() { return this->repositoryOfProjects.getSize(); };
	int totalQuantity();
	/*Calculate the total quantity of spare parts employed by finished projects
		Output: totalQuantity - int
	*/
};

