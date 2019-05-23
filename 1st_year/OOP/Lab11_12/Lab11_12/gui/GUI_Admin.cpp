#include "GUI_Admin.h"
#include <sstream>
#include "qdialog.h"
std::vector<std::string> GUI_Admin::tokenize(std::string line)
{
	std::vector<std::string> result;
	std::stringstream ss(line);
	std::string token;
	while (std::getline(ss, token, ','))
		result.push_back(token);
	return result;
}
GUI_Admin::GUI_Admin(Controller* controller)
{
	controller_ = controller;
	initGUI();
	connectSignalsAndSlots();
	display();

}
void GUI_Admin::initGUI()
{
	//records list
	QVBoxLayout* vertLayout = new QVBoxLayout;
	this->setLayout(vertLayout);
	QLabel* recordsLabel = new QLabel("&Records");
	recordsList_ = new QListWidget;
	recordsLabel->setBuddy(recordsList_);
	vertLayout->addWidget(recordsLabel);
	vertLayout->addWidget(recordsList_);

	//text boxes
	QFormLayout* formLayout = new QFormLayout;
	QWidget* textBoxes = new QWidget;
	textBoxes->setLayout(formLayout);
	titleTextBox_ = new QLineEdit;
	locationTextBox_ = new QLineEdit;
	dateTextBox_ = new QLineEdit;
	numberOfAccessingsTextBox_ = new QLineEdit;
	recordPathLabel_ = new QLineEdit;
	QLabel* titleLabel = new QLabel("&Title");
	titleLabel->setBuddy(titleTextBox_);
	QLabel* genreLabel = new QLabel("&Location");
	genreLabel->setBuddy(locationTextBox_);
	QLabel* yearLabel = new QLabel("&Date of creation");
	yearLabel->setBuddy(dateTextBox_);
	QLabel* likesLabel = new QLabel("&Number accessings");
	likesLabel->setBuddy(numberOfAccessingsTextBox_);
	QLabel* trailerLabel = new QLabel("&Record's path");
	trailerLabel->setBuddy(recordPathLabel_);
	formLayout->addRow(titleLabel, titleTextBox_);
	formLayout->addRow(genreLabel, locationTextBox_);
	formLayout->addRow(yearLabel, dateTextBox_);
	formLayout->addRow(likesLabel, numberOfAccessingsTextBox_);
	formLayout->addRow(trailerLabel, recordPathLabel_);
	vertLayout->addWidget(textBoxes);

	//buttons
	QGridLayout* gridLayout = new QGridLayout;
	QWidget* buttons = new QWidget;
	buttons->setLayout(gridLayout);
	addButton_ = new QPushButton("&Add");
	deleteButton_ = new QPushButton("&Delete");
	updateButton_ = new QPushButton("&Update");	
	changeModeButton_ = new QPushButton("&Change mode");	
	gridLayout->addWidget(addButton_);
	gridLayout->addWidget(deleteButton_);
	gridLayout->addWidget(updateButton_);
	gridLayout->addWidget(changeModeButton_);
	vertLayout->addWidget(buttons);
}
void GUI_Admin::display()
{
	if (recordsList_->count() > 0)
		recordsList_->clear();

	for (auto record: controller_->getRecords())
	{
		
		
		QListWidgetItem* newItem = new QListWidgetItem;
		QString newString = QString::fromStdString(record.toString());
		newItem->setText(newString);
		recordsList_->addItem(newItem);
	}


}
void GUI_Admin::connectSignalsAndSlots()
{
	QObject::connect(this, &GUI_Admin::recordsUpdatedSignal, this, &GUI_Admin::display);
	QObject::connect(addButton_, &QPushButton::clicked, this, &GUI_Admin::addRecordButtonHandler);
	QObject::connect(deleteButton_, &QPushButton::clicked, this, &GUI_Admin::deleteRecordButtonHandler);
	QObject::connect(updateButton_, &QPushButton::clicked, this, &GUI_Admin::updateRecordButtonHandler);
	QObject::connect(changeModeButton_, &QPushButton::clicked, this, &GUI_Admin::changeModeButtonHandler);
}
void GUI_Admin::addrecord(std::string& title, std::string& location,
	std::string& date, std::string& numberOfAccessings,
	std::string& path)
{
	controller_->addRecord(title, location, date, std::stoi(numberOfAccessings), path);
	controller_->saveRecordsInFile();
	emit recordsUpdatedSignal();
}
void GUI_Admin::updateRecord(std::string& title, std::string& location,
	std::string& date, std::string& numberOfAccessings,
	std::string& path)
{
	bool response;
	response = controller_->updateRecord(title, location, date, std::stoi(numberOfAccessings), path);
	QMessageBox* dialog = new QMessageBox;
	if (response == true)
	{
		dialog->setText("record updated");
		dialog->show();
		controller_->saveRecordsInFile();
		emit recordsUpdatedSignal();
	}
	else {
		dialog->setText("Update failed");
		dialog->show();
	}
	updateWindow_->close();
}
void GUI_Admin::addRecordButtonHandler()
{
	QString title = titleTextBox_->text();
	
	QString location = locationTextBox_->text();
	QString dateOfCreation = dateTextBox_->text();
	QString numberOfAccessings = numberOfAccessingsTextBox_->text();
	QString path = recordPathLabel_->text();
	titleTextBox_->clear();
	locationTextBox_->clear();
	dateTextBox_->clear();
	numberOfAccessingsTextBox_->clear();
	recordPathLabel_->clear();
	emit addrecord(title.toStdString(), location.toStdString()
		, dateOfCreation.toStdString(), numberOfAccessings.toStdString()
		, path.toStdString());
}
void GUI_Admin::deleteRecordButtonHandler()
{
	QListWidgetItem* newItem = recordsList_->currentItem();
	QString details = newItem->text();
	std::vector<std::string> tokens = tokenize(details.toStdString());
	controller_->deleteRecord(tokens[0]);
	controller_->saveRecordsInFile();
	emit recordsUpdatedSignal();
}
void GUI_Admin::updateRecordButtonHandler()
{
	updateWindow_ = new QWidget;
	QFormLayout* formLayout = new QFormLayout;
	updateWindow_->setLayout(formLayout);
	QLabel* titleLabel = new QLabel("&Title");
	QLabel* locationLabel = new QLabel("&New location");
	QLabel* dateLabel = new QLabel("&New date of creation");
	QLabel* accessingsLabel = new QLabel("&New number of accessings");
	QLabel* pathLabel = new QLabel("&New path link");
	newTitleTextBox_ = new QLineEdit;
	newGenreTextBox_ = new QLineEdit;
	newYearTextBox_ = new QLineEdit;
	newLikesTextBox_ = new QLineEdit;
	newTrailerTextBox_ = new QLineEdit;
	updaterecordButton_ = new QPushButton("&Update");
	cancelButton_ = new QPushButton("&Cancel");
	QObject::connect(updaterecordButton_, &QPushButton::clicked, this, &GUI_Admin::updateButtonHandler);
	QObject::connect(cancelButton_, &QPushButton::clicked, updateWindow_, &QWidget::close);
	titleLabel->setBuddy(newTitleTextBox_);
	locationLabel->setBuddy(newGenreTextBox_);
	dateLabel->setBuddy(newYearTextBox_);
	accessingsLabel->setBuddy(newLikesTextBox_);
	pathLabel->setBuddy(newTrailerTextBox_);
	formLayout->addRow(titleLabel,newTitleTextBox_);
	formLayout->addRow(locationLabel, newGenreTextBox_);
	formLayout->addRow(dateLabel, newYearTextBox_);
	formLayout->addRow(accessingsLabel, newLikesTextBox_);
	formLayout->addRow(pathLabel, newTrailerTextBox_);
	formLayout->addRow(updaterecordButton_, cancelButton_);
	updateWindow_->show();
}
void GUI_Admin::changeModeButtonHandler()
{
	GUI_User* userGUI = new GUI_User(this);
	//this->hide();
}
void GUI_Admin::updateButtonHandler()
{
	QString title = newTitleTextBox_->text();
	QString newGenre = newGenreTextBox_->text();
	QString newYear = newYearTextBox_->text();
	QString newLikes = newLikesTextBox_->text();
	QString newTrailer = newTrailerTextBox_->text();
	emit updateRecord(title.toStdString(), newGenre.toStdString(),
		newYear.toStdString(), newLikes.toStdString(),
		newTrailer.toStdString());

}
QListWidgetItem*  GUI_Admin::getSelectedItem()
{
	return recordsList_->currentItem();
}