#pragma once
#include <QtWidgets>
#include "service/Controller.h"
#include "GUI_Admin.h"
class GUI_User : public QWidget
{
	Q_OBJECT
	friend class GUI_Admin;
private:
	Repository* myList_;
	QListWidget* myListWidget_;
	QPushButton* saveButton_;
	QPushButton* nextButton_;
	QLabel* currentRecordLabel_;
	QPushButton* changeModeButton_;
	//QPushButton* myListButton_;
	Controller* myListController_;
	GUI_Admin* adminGUI_;
	SecurityRecord currentRecord;
public:
	GUI_User(QWidget* parent = Q_NULLPTR) {}
	GUI_User(const GUI_User& guiUser) {}
	GUI_User(GUI_Admin* adminGUI);
private:
	void display();
	void connectSignalsAndSlots();
	void initGUI();
	void saveButtonHandler();
	void nextButtonHandler();
	void changeModeButtonHandler();
	std::vector<std::string> tokenize(std::string line);
signals:
	void myListUpdatedSignal();
	void nextRecordSignal();
	void saveRecordSignal(std::string& title);
public slots:
	void saveRecord(std::string& title);
	void nextRecord(std::string title);


};
//class GUIMyListDisplay : public QWidget
//{
//private:
//	QListWidget* myListDisplay_;
//public:
//	GUIMyListDisplay(QWidget* parent = Q_NULLPTR) {}
//	GUIMyListDisplay(const GUIMyListDisplay& myListDisplay) {}
//	GUIMyListDisplay(QLayout* parent);
//	void Display(Controller* myListController);
//};
//class GUIUserButtons : public QWidget
//{
//private:
//	QPushButton* playButton_;
//	QPushButton* nextButton_;
//public:
//	GUIUserButtons(QWidget* parent = Q_NULLPTR) {}
//	GUIUserButtons(const GUIUserButtons& userButtons) {}
//	GUIUserButtons(QLayout* parent);
//
//};
//class GUI_User :public QVBoxLayout
//{
//private:
//	Controller* controller_;
//	Controller* myListController_;
//	recordRepo* myList_;
//	GUIMyListDisplay* myListDisplay_;
//	GUIUserButtons* userButtons_;
//public:
//	GUI_User(QWidget* parent = Q_NULLPTR) {}
//	GUI_User(const GUI_User& guiUser) {}
//	GUI_User(Controller* controller);
//};