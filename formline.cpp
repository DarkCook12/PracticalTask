#include "formline.h"
#include "ui_formline.h"

FormLine::FormLine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLine)
{
    ui->setupUi(this);
    x = 0;
    y = 0;
    a = 0;
    widget = new widgetPaint(this);
    widget->setGeometry(340,10,351,341);
    connect(this, &FormLine::signalLine, widget, &widgetPaint::slotLine);
}

FormLine::~FormLine()
{
    delete ui;
}

void FormLine::on_horizontalScrollBarX_valueChanged(int value)
{
    x = value;
    emit signalLine(x, y, a);
}


void FormLine::on_horizontalScrollBarY_valueChanged(int value)
{
    y = value;
    emit signalLine(x, y, a);

}


void FormLine::on_spinBox_valueChanged(int arg1)
{
    a = arg1;
    emit signalLine(x, y, a);

}


void FormLine::on_pushGenerate_clicked()
{
    emit signalMain(x, y, a);
}

