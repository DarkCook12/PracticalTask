#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <widgetpaint.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    widget = new widgetPaint(this);
    widget->setGeometry(15,50,781,511);
    connect(this, &MainWindow::signalPaint, widget, &widgetPaint::slotPaint);
    connect(this, &MainWindow::signalLine, widget, &widgetPaint::slotLine);
    connect(this, &MainWindow::signalStart, widget, &widgetPaint::slotStart);

    square = new FormSquare;
    connect(square, &FormSquare::signalSquare, this, &MainWindow::slotSquare);

    line = new FormLine;
    connect(line, &FormLine::signalMain, this, &MainWindow::slotLine);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete widget;
    delete square;
    delete line;

}

void MainWindow::slotSquare(int x, int y, int a)
{
    square->close();
    emit signalPaint(x, y, a);
}

void MainWindow::slotLine(int x, int y, int a)
{
    line->close();
    emit signalLine(x, y, a);
}


void MainWindow::on_actionSize_triggered()
{
    square->show();
}


void MainWindow::on_actionLine_triggered()
{
    line->show();
}


void MainWindow::on_actionPlay_triggered()
{
    emit signalStart();
}

