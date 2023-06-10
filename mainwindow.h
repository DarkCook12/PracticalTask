#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formsquare.h"
#include "formline.h"
#include "widgetpaint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

    void signalPaint(int x, int y, int a);

    void signalLine(int x, int y, int a);

    void signalStart();

public slots:
    void slotSquare(int x, int y, int a);

    void slotLine(int x, int y, int a);
private slots:
    void on_actionSize_triggered();

    void on_actionLine_triggered();

    void on_actionPlay_triggered();

private:
    widgetPaint* widget;
    FormSquare* square;
    FormLine* line;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
