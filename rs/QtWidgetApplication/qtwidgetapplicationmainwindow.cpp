#include "qtwidgetapplicationmainwindow.h"
#include "./ui_qtwidgetapplicationmainwindow.h"

QtWidgetApplicationMainWindow::QtWidgetApplicationMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtWidgetApplicationMainWindow)
{
    ui->setupUi(this);
}

QtWidgetApplicationMainWindow::~QtWidgetApplicationMainWindow()
{
    delete ui;
}
