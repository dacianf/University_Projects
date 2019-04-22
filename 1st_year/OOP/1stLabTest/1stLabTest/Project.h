#pragma once
#include <string>
#include "Date.h"
class Project
{
private:
	std::string name;
	std::string sector;
	Date date;
	int quantity;
	bool isDone;
public:
	Project() :name(" "), sector(" "), date(Date()), quantity(1), isDone(false) {};
	Project(std::string name, std::string sector, std::string date, int quantity, bool isDone):
		name(name), sector(sector), date(date), quantity(quantity), isDone(isDone) {}
	~Project() {};
	const std::string& getName() const{ return this->name; }
	const std::string& getSector() const{ return this->sector; }
	const Date& getDate() const{ return this->date; }
	const int& getQuantity() const{ return this->quantity; }
	const bool& getFinalization() const{ return this->isDone; }
	bool operator ==(Project& prj) {
		return this->name == prj.name;
	}
	Project operator=(Project prj) {
		this->date = prj.date;
		this->name = prj.name;
		this->sector = prj.sector;
		this->quantity = prj.quantity;
		this->isDone = prj.isDone;
		return *this;
	}

	bool operator<(Project& prj) {

		return this->date < prj.date;

	}
};

