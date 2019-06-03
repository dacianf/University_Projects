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
	QVBoxLayout* verticalLayout = new QVBoxLayout;
	this->setLayout(verticalLayout);

	saveButton_ = new QPushButton("&Save");
	changeModeButton_ = new QPushButton("&Change mode");
	myListButton_ = new QPushButton("&My List");
	nextButton_ = new QPushButton("&Next");

	QWidget* myListPart = new QWidget;
	QLabel* myListLabel = new QLabel("&My list");
	myListWidget_ = new QListWidget;

	currentRecordLabel_ = new QLabel;
	currentRecordLabel_->setText(QString(this->currentRecord.toString().c_str()));

	verticalLayout->addWidget(currentRecordLabel_);
	verticalLayout->addWidget(nextButton_);
	verticalLayout->addWidget(myListButton_);
	verticalLayout->addWidget(saveButton_);
	verticalLayout->addWidget(changeModeButton_);
	
	this->createUndoRedoMenu();
	this->show();
	//userWindow->show();
}

void GUI_User::createMyListTable() {
	auto tableView = new QTableView;
	this->tabelModelRecords_ = new RecordsTableModel(this->myList_, this);
	tableView->setModel(this->tabelModelRecords_);
	tableView->resizeColumnsToContents();
	int clW = 9;
	for (int i = 0; i < tabelModelRecords_->columnCount(); i++)
		clW += tableView->columnWidth(i);
	tableView->setMinimumWidth(clW);
	tableView->setMinimumHeight(tableView->rowHeight(0) * 15);
	auto colour = tableView->horizontalHeader()->palette();
	colour.setColor(QPalette::Normal, QPalette::Window, Qt::gray);
	tableView->horizontalHeader()->setPalette(colour);
	tableView->setItemDelegate(new PlayButton{});
	tableView->show();
}
void GUI_User::connectSignalsAndSlots()
{
	QObject::connect(this, &GUI_User::myListUpdatedSignal, this, &GUI_User::display);
	QObject::connect(saveButton_, &QPushButton::clicked, this, &GUI_User::saveButtonHandler);
	QObject::connect(nextButton_, &QPushButton::clicked, this, &GUI_User::nextButtonHandler);
	QObject::connect(changeModeButton_, &QPushButton::clicked, this, &GUI_User::changeModeButtonHandler);
	QObject::connect(myListButton_, &QPushButton::clicked, this, &GUI_User::myListButtonHandler);
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

void GUI_User::undo()
{
	if (!this->adminGUI_->controller_->undoUser()) {
		auto errorMessage = new QMessageBox();
		errorMessage->setText("No more undos!!!");
		errorMessage->setIcon(QMessageBox::Warning);
		errorMessage->setWindowTitle("Info");
		errorMessage->show();
	}
	this->display();
}
void GUI_User::redo()
{
	if (!this->adminGUI_->controller_->redoUser()) {
		auto errorMessage = new QMessageBox();
		errorMessage->setText("No more redos!!!");
		errorMessage->setIcon(QMessageBox::Warning);
		errorMessage->setWindowTitle("Info");
		errorMessage->show();
	}
	this->display();
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
	//*QListWidgetItem* newItem = adminGUI_->getSelectedItem();
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
void GUI_User::myListButtonHandler()
{
	this->createMyListTable();
}
void GUI_User::changeModeButtonHandler()
{
	this->hide();
}
void GUI_User::createUndoRedoMenu()
{
	this->menuBar_ = new QMenuBar();
	this->editMenu_ = new QMenu();
	this->menuBar_->addMenu(editMenu_);

	this->undo_action = new QAction("Undo", this);
	this->undo_action->setShortcuts(QKeySequence::Undo);
	connect(undo_action, &QAction::triggered, this, &GUI_User::undo);

	this->redo_action = new QAction("Redo", this);
	this->redo_action->setShortcuts(QKeySequence::Redo);
	connect(redo_action, &QAction::triggered, this, &GUI_User::redo);
	
	this->editMenu_->setTitle("Edit");
	this->editMenu_->addAction(undo_action);
	this->editMenu_->addAction(redo_action);
	this->layout()->setMenuBar(menuBar_);
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