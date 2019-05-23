#include <QtWidgets>
#include "service/Controller.h"
#include "GUI_User.h"
#include "GUI_Admin.h"
void DisplayRecords(QLayout* adminWindow)
{
	QWidget* listAll = new QWidget;
	QVBoxLayout* vLayout = new QVBoxLayout;
	listAll->setLayout(vLayout);
	QLabel* recordsLabel = new QLabel("&records");
	QListWidget* recordsList = new QListWidget;
	recordsLabel->setBuddy(recordsList);
	vLayout->addWidget(recordsLabel);
	vLayout->addWidget(recordsList);
	
	adminWindow->addWidget(listAll);

}
void RecordsInfoInput(QLayout* adminWindow)
{
	QWidget* inputWidget = new QWidget();
	
	QFormLayout* formLayout = new QFormLayout;
	QLabel* titleLabel = new QLabel("&Title");
	QLineEdit* titleTextBox = new QLineEdit();
	titleLabel->setBuddy(titleTextBox);
	QLabel* locationLabel = new QLabel("&Location");
	QLineEdit* locationTextBox = new QLineEdit();
	locationLabel->setBuddy(locationTextBox);
	QLabel* dateOfCreationLabel = new QLabel("&Date of creation");
	QLineEdit* dateOfCreationTextBox = new QLineEdit();
	dateOfCreationLabel->setBuddy(dateOfCreationTextBox);
	QLabel* numberOfAccessingsLabel = new QLabel("&Number of accessings");
	QLineEdit* numberOfAccessingsTextBox = new QLineEdit();
	numberOfAccessingsLabel->setBuddy(numberOfAccessingsTextBox);
	QLabel* recordPathLabel = new QLabel("&Location path");
	QLineEdit* recordPathTextBox = new QLineEdit();
	recordPathLabel->setBuddy(recordPathTextBox);
	formLayout->addRow(titleLabel, titleTextBox);
	formLayout->addRow(locationLabel, locationTextBox);
	formLayout->addRow(dateOfCreationLabel, dateOfCreationTextBox);
	formLayout->addRow(numberOfAccessingsLabel, numberOfAccessingsTextBox);
	formLayout->addRow(recordPathLabel, recordPathTextBox);
	formLayout->addRow(titleLabel, titleTextBox);
	inputWidget->setLayout(formLayout);
	adminWindow->addWidget(inputWidget);

}
void AdminButtons(QLayout* adminWindow)
{
	QGridLayout* gridLayout = new QGridLayout;
	QWidget* buttonsWidget = new QWidget;
	buttonsWidget->setLayout(gridLayout);
	QPushButton* addButton = new QPushButton("&Add");
	QPushButton* deleteButton = new QPushButton("&Delete");
	QPushButton* updateButton = new QPushButton("&Update");
	QPushButton* filterButton = new QPushButton("&Filter");
	gridLayout->addWidget(addButton);
	gridLayout->addWidget(deleteButton);
	gridLayout->addWidget(updateButton);
	gridLayout->addWidget(filterButton);
	adminWindow->addWidget(buttonsWidget);

}


void MyList(QLayout* userWindow)
{
	QVBoxLayout* hLayout = new QVBoxLayout;
	QWidget* myListWidget = new QWidget;
	myListWidget->setLayout(hLayout);
	QListWidget* myList = new QListWidget;
	QLabel* myListLabel = new QLabel("My list");
	myListLabel->setBuddy(myList);
	hLayout->addWidget(myListLabel);
	hLayout->addWidget(myList);
	userWindow->addWidget(myListWidget);

}
void AddToMyListButton(QLayout* layout)
{
	QPushButton* addToMyListButton = new QPushButton(">");
	layout->addWidget(addToMyListButton);
}
void UserButtons(QLayout* layout)
{
	QGridLayout* gridLayout = new QGridLayout;
	QWidget* userButtons = new QWidget;
	userButtons->setLayout(gridLayout);
	QPushButton* nextButton = new QPushButton("&Next");
	QPushButton* playButton = new QPushButton("&Play record");
	gridLayout->addWidget(playButton);
	gridLayout->addWidget(nextButton);
	layout->addWidget(userButtons);
	
}
Repository* readSettings() {
	std::ifstream fin;
	fin.open("settings.st", std::fstream::in | std::fstream::out);
	std::string line;
	Repository* repository_;
	fin >> line;
	if (line == "memory")repository_ = new Repository;
	else if (line == "file") {
		fin >> line;
		repository_ = new File_Repository(line);
	}
	fin.close();
	return repository_;
}

int main(int argc, char** argv)
{
	Repository* recordsRepository = readSettings();
	Repository* savedRepository = new Repository();
	Controller* controller = new Controller(recordsRepository, savedRepository);
	QApplication app(argc, argv);
	QWidget* mainWindow = new QWidget;
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainWindow->setLayout(mainLayout);
	app.setApplicationName("Records Database");
	GUI_Admin* adminGUI = new GUI_Admin(controller);
	mainLayout->addWidget(adminGUI);
	mainWindow->show();
	return app.exec();

}
