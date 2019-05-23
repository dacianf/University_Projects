#include "GUI_User.h"
#include <sstream>
GUI_User::GUI_User(GUI_Admin* adminGUI)
{
	adminGUI_ = adminGUI;
	myListController_ = adminGUI_->controller_;
	myList_ = myListController_->getCopyOfSavedRepository();
	myListController_->setRecordsPath("./data/records.txt");
	initGUI();
	currentRecord = adminGUI_->controller_->nextRecord();
	currentRecordLabel_->setText(QString(this->currentRecord.toString().c_str()));
	connectSignalsAndSlots();
	display();
}
void GUI_User::initGUI()
{
	//QWidget* userWindow = new QWidget;
	QHBoxLayout* horizontalLayout = new QHBoxLayout;
	this->setLayout(horizontalLayout);
	//userWindow->setLayout(horizontalLayout);
	saveButton_ = new QPushButton("&Save");
	changeModeButton_ = new QPushButton("&Change mode");
	horizontalLayout->addWidget(saveButton_);
	QWidget* myListPart = new QWidget;
	QVBoxLayout* verticalLayout = new QVBoxLayout;
	myListPart->setLayout(verticalLayout);
	QLabel* myListLabel = new QLabel("&My list");
	myListWidget_ = new QListWidget;
	myListLabel->setBuddy(myListWidget_);
	verticalLayout->addWidget(myListLabel);
	verticalLayout->addWidget(myListWidget_);
	nextButton_ = new QPushButton("&Next");
	currentRecordLabel_ = new QLabel;
	currentRecordLabel_->setText(QString(this->currentRecord.toString().c_str()));
	verticalLayout->addWidget(nextButton_);
	verticalLayout->addWidget(currentRecordLabel_);
	verticalLayout->addWidget(changeModeButton_);
	horizontalLayout->addWidget(myListPart);
	this->show();
	//userWindow->show();
}
void GUI_User::connectSignalsAndSlots()
{
	QObject::connect(this, &GUI_User::myListUpdatedSignal, this, &GUI_User::display);
	QObject::connect(saveButton_, &QPushButton::clicked, this, &GUI_User::saveButtonHandler);
	QObject::connect(nextButton_, &QPushButton::clicked, this, &GUI_User::nextButtonHandler);
	QObject::connect(changeModeButton_, &QPushButton::clicked, this, &GUI_User::changeModeButtonHandler);
}
void GUI_User::display()
{
	if (myListWidget_->count() > 0)
		myListWidget_->clear();
	auto records = myList_->getRecords();
	if(records.size())
		for (auto records : myList_->getRecords())
		{

			QListWidgetItem* newItem = new QListWidgetItem;
			QString newString = QString::fromStdString(records.toString());
			newItem->setText(newString);
			myListWidget_->addItem(newItem);
		}
}
std::vector<std::string> GUI_User::tokenize(std::string line)
{
	std::vector<std::string> result;
	std::stringstream ss(line);
	std::string token;
	while (std::getline(ss, token, ','))
		result.push_back(token);
	return result;
}
void GUI_User::nextRecord(std::string title)
{
	this->currentRecordLabel_->setText(QString(this->currentRecord.toString().c_str()));
	emit nextRecordSignal();
}
void GUI_User::saveRecord(std::string& title)	
{
	
	myListController_->saveTitle(title);
	
	emit myListUpdatedSignal();
}
void GUI_User::saveButtonHandler()
{
	///*QListWidgetItem* newItem = adminGUI_->getSelectedItem();
	//QString details = newItem->text();*/
	//std::vector<std::string> tokens = tokenize(details.toStdString());
	//if (tokens.size() != 5)
	//	throw std::exception("Invalid selection!\n");
	std::string title = this->currentRecord.getTitle();
	emit saveRecord(title);
}
void GUI_User::nextButtonHandler()
{
	this->currentRecord = this->adminGUI_->controller_->nextRecord();
	emit nextRecord(currentRecord.getTitle());
}
void GUI_User::changeModeButtonHandler()
{
	this->hide();
}
//GUIMyListDisplay::GUIMyListDisplay(QLayout* parent)
//{
//
//	QVBoxLayout* verticalLayout = new QVBoxLayout;
//	this->setLayout(verticalLayout);
//	QLabel* myListLabel = new QLabel("&My list");
//	myListDisplay_ = new QListWidget;
//	myListLabel->setBuddy(myListDisplay_);
//	verticalLayout->addWidget(myListLabel);
//	verticalLayout->addWidget(myListDisplay_);
//	parent->addWidget(this);
//}
//GUI_User::GUI_User(Controller* controller)
//{
//	controller_ = controller;
//	myList_ = new recordRepo;
//	
//	myListDisplay_ = new GUIMyListDisplay(this);
//	userButtons_ = new GUIUserButtons(this);
//}
//GUIUserButtons::GUIUserButtons(QLayout* parent)
//{
//	QHBoxLayout* horizontalLayout = new QHBoxLayout;
//	this->setLayout(horizontalLayout);
//	playButton_ = new QPushButton("Play");
//	nextButton_ = new QPushButton("Next");
//	horizontalLayout->addWidget(playButton_);
//	horizontalLayout->addWidget(nextButton_);
//	parent->addWidget(this);
//}