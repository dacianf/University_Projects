#pragma once
#include <QStyledItemDelegate>
class PlayButton :
	public QStyledItemDelegate
{	Q_OBJECT
public:
	explicit PlayButton(QObject *parent = 0);
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
signals:
	void btnClicked(const QModelIndex&);
};

