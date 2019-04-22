#include "UI.h"
#include <exception>

void UI::start()
{
	this->printMenu();
	std::cout << ">";
	int command = -1;
	while (command != 0) {
		std::cin >> command;
		if (command == 1)
			this->add();
		else if (command == 2)
			this->printList(this->controller.getAll());
		else if (command == 3)
			this->getTotal();
	}
}

void UI::printMenu()
{
	std::string strToPrint = "Welcome!\n";
	strToPrint += "\t1 - add\n";
	strToPrint += "\t2 - list all\n";
	strToPrint += "\t3 - total quantity";
	strToPrint += "\t0 - exit\n";
	std::cout << strToPrint;
}

void UI::printProject(Project & x)
{
	std::cout << x.getName() << "\t" << x.getSector() << "\t" << x.getDate() << "\t" << x.getQuantity() << "\t" << x.getFinalization() << "\n";
}

void UI::printList(std::vector<Project> listToPrint)
{
	std::sort(listToPrint.begin(), listToPrint.end());
	for (int i = 0; i < listToPrint.size(); i++)
		this->printProject(listToPrint[i]);
}

void UI::add()
{
	std::string name;
	std::string sector;
	std::string date;
	int quantity;
	bool isDone;
	std::cin >> name >> sector >> date >> quantity >> isDone;
	bool ok;
	try {
		ok = this->controller.addProject(name, sector, date, quantity, isDone);
	}
	catch (char*){
		std::cout << "invalid format\n";
	}
	if (ok == false)
		std::cout << "element not added!\n";		
	else std::cout << "element added!\n";
}

void UI::getTotal()
{
	std::cout << this->controller.totalQuantity();
}
