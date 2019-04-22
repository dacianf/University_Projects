#pragma once
#include "Project.h"
#include <vector>
class Repo
{
private:
	std::vector<Project> listOfProjects;
public:
	Repo() {};
	~Repo() {};

	/*adds a project to the listOfProjects
		Input: projectToAdd - reference to a new project that is want to be add
		Output: false - if the project was not add
				true - otherwise
	*/
	bool addProject(Project& projectToAdd) {
		if (this->findProject(projectToAdd.getName()) != -1)
			return false;
		this->listOfProjects.push_back(projectToAdd);
		return true;
	}

	int getSize() { return this->listOfProjects.size(); }

	const std::vector<Project> getAll() const
	{
		return this->listOfProjects;
	}

	int findProject(std::string name) {
		for (int i = 0; i < this->listOfProjects.size(); i++)
			if (this->listOfProjects[i].getName() == name)
				return i;
		return -1;
	}
};

