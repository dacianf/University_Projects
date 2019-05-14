#include "Lab11_12.h"
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlistwidget.h>
#include <QtCharts>


Lab11_12::Lab11_12(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	auto _recordsRepository = new File_Repository("./data/records.txt");
	auto _savedRepository = new Repository();
	this->controller = new Controller(_recordsRepository, _savedRepository);
	this->mainWidget = new QWidget(this);
	this->chartsWidget = new QWidget(this);
	this->createChartsWidget();
	this->createMainWidget();
}

void Lab11_12::createMainWidget()
{
	QPushButton *addButton = new QPushButton("Add record");
	QPushButton *removeButton = new QPushButton("Remove record");
	QPushButton *updateButton = new QPushButton("Update record");
	QPushButton *closeButton = new QPushButton("Close");
	QPushButton *listButton = new QPushButton("List record");
	QPushButton *chartsButton = new QPushButton("See graphic");
	QSpacerItem *spacerButtons = new QSpacerItem(1, 100);
	QListWidget *recordsbox = new QListWidget();
	QGridLayout *layout = new QGridLayout();
	this->mainWidget->setLayout(layout);

	layout->addWidget(addButton, 0, 0);
	layout->addWidget(removeButton, 0, 1);
	layout->addWidget(updateButton, 1, 0);
	layout->addWidget(listButton, 1, 1);
	layout->addWidget(recordsbox, 3, 2);
	layout->addWidget(closeButton, 3, 0);
	layout->addWidget(chartsButton, 3, 1);
	auto mainWG = this->mainWidget;
	auto chartWG = this->chartsWidget;
	connect(chartsButton, &QPushButton::clicked,
		[mainWG, chartWG, this]() {
			mainWG->hide();
			chartWG->show();
			this->setCentralWidget(chartWG);
		});
	connect(listButton, &QPushButton::clicked,
		[recordsbox, this](){
			if (recordsbox->count())recordsbox->clear();
			else {
				QList<QString> recordsAsString;
				for (auto record : this->getRecordsFromRepo())
					recordsAsString.push_back(QString(record.toString().c_str()));
				recordsbox->addItems(recordsAsString);
			}
		});
	connect(closeButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
	this->setCentralWidget(this->mainWidget);
}

void Lab11_12::createChartsWidget()
{
	QList <QBarSet*> bars;
	for (auto record : this->getRecordsFromRepo())
		bars.push_back(new QBarSet(record.getTitle().c_str()));
	QBarSeries *series = new QBarSeries();
	series->append(bars);
	QChart *chart = new QChart();
	chart->addSeries(series);
	chart->setTitle("Number of accessings of each user");

	QChartView *chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	this->chartsWidget->close();
}

const std::vector<SecurityRecord> Lab11_12::getRecordsFromRepo() const
{
	return this->controller->getRecords();
}
