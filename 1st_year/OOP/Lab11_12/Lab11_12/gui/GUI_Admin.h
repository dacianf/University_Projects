#pragma once
#include <QtWidgets>
#include "service/Controller.h"
#include "GUI_User.h"

class GUI_Admin :public QWidget
{
	Q_OBJECT
	friend class GUI_User;
private:
	QListWidget* recordsList_;
	QLineEdit* titleTextBox_;
	QLineEdit* locationTextBox_;
	QLineEdit* dateTextBox_;
	QLineEdit* numberOfAccessingsTextBox_;
	QLineEdit* recordPathLabel_;
	QLineEdit* newTitleTextBox_;
	QLineEdit* newGenreTextBox_;
	QLineEdit* newYearTextBox_;
	QLineEdit* newLikesTextBox_;
	QLineEdit* newTrailerTextBox_;
	QPushButton* addButton_;
	QPushButton* deleteButton_;
	QPushButton* updateButton_;
	QPushButton* updaterecordButton_;
	QPushButton* cancelButton_;
	QPushButton* changeModeButton_;
	
	Controller* controller_;
	QWidget* updateWindow_;
public:
	GUI_Admin(QWidget* parent = Q_NULLPTR) {}
	GUI_Admin(const GUI_Admin& admin) {}
	GUI_Admin(Controller* controller);
	QListWidgetItem* getSelectedItem();

private:
	std::vector<std::string> tokenize(std::string line);
	void display();
	void connectSignalsAndSlots();
	void addRecordButtonHandler();
	void deleteRecordButtonHandler();
	void updateRecordButtonHandler();
	void changeModeButtonHandler();
	void updateButtonHandler();
	void initGUI();

signals:
	void recordsUpdatedSignal();
	void addrecordSignal(std::string& title, std::string& genre,
		std::string& yearOfRelease, std::string& numberOfLikes,
		std::string& link);
public slots:
	void addrecord(std::string& title, std::string& genre,
		std::string& yearOfRelease, std::string& numberOfLikes,
		std::string& link);
	void updateRecord(std::string& title, std::string& newGenre,
		std::string& newYearOfRelease, std::string& newNumberOfLikes,
		std::string& newLink);
};