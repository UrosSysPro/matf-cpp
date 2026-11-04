#ifndef QTWIDGETAPPLICATIONMAINWINDOW_H
#define QTWIDGETAPPLICATIONMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class QtWidgetApplicationMainWindow;
}
QT_END_NAMESPACE

class QtWidgetApplicationMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtWidgetApplicationMainWindow(QWidget *parent = nullptr);
    ~QtWidgetApplicationMainWindow() override;

private:
    Ui::QtWidgetApplicationMainWindow *ui;
};
#endif // QTWIDGETAPPLICATIONMAINWINDOW_H
