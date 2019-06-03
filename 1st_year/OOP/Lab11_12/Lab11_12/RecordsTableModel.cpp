#include "RecordsTableModel.h"
#include <QFont>
#include <QBrush>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
const int RecordsTableModel::ITEMS_PER_PAGE = 10;
RecordsTableModel::RecordsTableModel(Repository* r, QObject* parent) : QAbstractTableModel{ parent }, repo{ r }
{
	this->loadedRows = 0;
}

RecordsTableModel::~RecordsTableModel()
{
}

int RecordsTableModel::rowCount(const QModelIndex & parent) const
{
	int size = this->repo->getRecords().size();
	if (size <= this->loadedRows)
		return size;
	return this->loadedRows;
}

int RecordsTableModel::columnCount(const QModelIndex & parent) const
{
	return 6;
}

QVariant RecordsTableModel::data(const QModelIndex & index, int role) const
{
	// get the genes
	std::vector<SecurityRecord> records = this->repo->getRecords();
	
	int row = index.row();
	int column = index.column();

	// get the gene from the current row
	SecurityRecord securityRecord_ = records[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(securityRecord_.getTitle());
		case 1:
			return QString::fromStdString(securityRecord_.getLocation());
		case 2:
		{
			auto date = securityRecord_.getTimeOfCreation();
			return QString::fromStdString(date.toString().c_str());
		}
		case 3:
			return QString::number(securityRecord_.getNumberOfAccessing());
		case 4:
			return QString::fromStdString(securityRecord_.getFootagePreview());
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 12, 10, true);
		font.setItalic(false);
		return font;
	}
	/*if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{0, 250, 154} };
		}
	}*/

	return QVariant{};
}

QVariant RecordsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Title" };
			case 1:
				return QString{ "Location" };
			case 2:
				return QString{ "Date of creation" };
			case 3:
				return QString{ "Number of accessings" };
			case 4:
				return QString{ "Footage preview" };
			case 5:
				return QString{ "Play" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		return QBrush{ QColor{195, 205, 221} };
	}
	return QVariant{};
}

Qt::ItemFlags RecordsTableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}


bool RecordsTableModel::canFetchMore(const QModelIndex & parent) const
{
	return this->repo->getRecords().size() > this->loadedRows;
}

void RecordsTableModel::fetchMore(const QModelIndex & parent)
{
	int remainedItems = this->repo->getRecords().size() - this->loadedRows;
	int itemsToFetch = std::min(remainedItems, ITEMS_PER_PAGE);
	this->beginInsertRows(QModelIndex{}, this->loadedRows, this->loadedRows + itemsToFetch - 1);
	this->loadedRows += itemsToFetch;
	this->endInsertRows();
	
	// Uncomment - to show how many items were fetched
	//QMessageBox::information(NULL, "Time", "<font size = 20 > " + QString::number(this->loadedRows) + " items were fetched." + "</font>");
	//qDebug() << "Fetched: " << this->loadedRows;
}
