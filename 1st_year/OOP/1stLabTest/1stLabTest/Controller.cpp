#include "Controller.h"

bool Controller::addProject(std::string name, std::string sector, std::string date, int quantity, bool isDone)
{
	Project newPrj(name, sector, date, quantity, isDone);
	return this->repositoryOfProjects.addProject(newPrj);
}

std::vector<Project> Controller::getAll()
{
	auto newProjects = this->repositoryOfProjects.getAll();
	return newProjects;
}

int Controller::totalQuantity()
{
	int totalQuantity = 0;
	for (int i = 0; i < this->repositoryOfProjects.getAll().size(); i++)
		if (this->repositoryOfProjects.getAll()[i].getFinalization())
			totalQuantity += this->repositoryOfProjects.getAll()[i].getQuantity();
	return totalQuantity;
}
