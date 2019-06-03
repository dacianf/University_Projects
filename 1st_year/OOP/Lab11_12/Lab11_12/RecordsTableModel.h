#pragma once
#include <QAbstractTableModel>
#include "repository/Repository.h"
class RecordsTableModel :
	public QAbstractTableModel
{
private:
	Repository* repo;
	static const int ITEMS_PER_PAGE;
	int loadedRows; // count how many rows were loaded
public:
	RecordsTableModel(Repository* repo_, QObject* parent = NULL);
	~RecordsTableModel();

	// number of rows
	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

	// number of columns
	int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

	// Value at a given position
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	// add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	// used to set certain properties of a cell
	Qt::ItemFlags flags(const QModelIndex & index) const override;
protected:
	// override the following two methods for pagination
	bool canFetchMore(const QModelIndex & parent) const override;
	void fetchMore(const QModelIndex & parent) override;

};

