#include "formsquare.h"
#include "ui_formsquare.h"
#include <widgetpaint.h>

FormSquare::FormSquare(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSquare)
{
    paintSquare = new widgetPaint(this);
    paintSquare->setGeometry(340,10,351,341);
    x = 0;
    y = 0;
    a = 0;
    ui->setupUi(this);
    connect(this, &FormSquare::signalPaintSquare, paintSquare, &widgetPaint::slotPaintSquare);
}

FormSquare::~FormSquare()
{
    delete ui;
}

void FormSquare::on_horizontalScrollBarX_valueChanged(int value)
{
    x = value;
    emit signalPaintSquare(x, y, a);
}


void FormSquare::on_horizontalScrollBarY_valueChanged(int value)
{
    y = value;
    emit signalPaintSquare(x, y, a);
}


void FormSquare::on_spinBox_valueChanged(int arg1)
{
    a = arg1;
    emit signalPaintSquare(x, y, a);
}



void FormSquare::on_pushGenerate_clicked()
{
    emit signalSquare(x, y, a);
}

