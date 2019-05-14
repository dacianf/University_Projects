#include "Lab11_12.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab11_12 w;
	w.addToolBar("Lab 11_12");
	w.show();
	return a.exec();
}
