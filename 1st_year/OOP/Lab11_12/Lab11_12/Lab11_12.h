#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab11_12.h"
#include "service/Controller.h"
#include <QtCharts>

class Lab11_12 : public QMainWindow
{
	Q_OBJECT
public:
	Lab11_12(QWidget *parent = Q_NULLPTR);
	~Lab11_12() { 
		delete this->controller;
	}
	QWidget* getMainWidget() const { return this->mainWidget; }
	QWidget* getChartsWidget() const { return this->chartsWidget; }
	const std::vector<SecurityRecord> getRecordsFromRepo()const;
private:
	QWidget* mainWidget;
	QWidget* chartsWidget;
	QChart* chart;
	Ui::Lab11_12Class ui;
	void createMainWidget();
	void createChartsWidget();
	Controller* controller;
};
