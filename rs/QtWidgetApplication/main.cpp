#include "qtwidgetapplicationmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetApplicationMainWindow w;
    w.show();
    return QApplication::exec();
}
