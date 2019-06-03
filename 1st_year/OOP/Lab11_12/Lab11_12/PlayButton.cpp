#include "PlayButton.h"
#include <QPixmap>
#include <QPainter>
#include <QEvent>
#include <Windows.h>
#include <QDebug>

PlayButton::PlayButton(QObject *parent) : QStyledItemDelegate(parent)
{
}

QSize PlayButton::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	//// return the QSize of the item in Your view
	if (index.column() == 5)
	{
		return QSize(10, 10);
	}

	return QStyledItemDelegate::sizeHint(option, index);

}

bool PlayButton::editorEvent(QEvent * event, QAbstractItemModel * model, const QStyleOptionViewItem & option, const QModelIndex & index)
{
	
	if (event->type() == QEvent::MouseButtonRelease && index.column() == 5) {
		auto filePath = model->index(index.row(), 4).data().toString().toStdString();
		
		qDebug() << filePath.c_str();
		ShellExecuteA(NULL, "open", filePath.c_str(),
			NULL, NULL, SW_SHOWNORMAL);
		//ShellExecute(NULL, L"open", L"C:\\da.html", NULL, NULL, SW_SHOWNORMAL);
		emit btnClicked(index);
	}
	return true;
}

void PlayButton::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	////optional : implement custom painting - text, images, drawings, and such
	QString record = index.model()->data(index, Qt::EditRole).toString();
	if (index.column() != 5) {
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}
	QPixmap	pixMap("play.png");
	painter->drawPixmap(option.rect, pixMap);
}
