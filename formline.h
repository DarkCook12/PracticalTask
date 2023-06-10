#ifndef FORMLINE_H
#define FORMLINE_H

#include <QWidget>
#include "widgetpaint.h"

namespace Ui {
class FormLine;
}

class FormLine : public QWidget
{
    Q_OBJECT

public:
    explicit FormLine(QWidget *parent = nullptr);
    ~FormLine();

signals:
    void signalLine(int x, int y, int a);

    void signalMain(int x, int y, int a);
private slots:
    void on_horizontalScrollBarX_valueChanged(int value);

    void on_horizontalScrollBarY_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_pushGenerate_clicked();

private:
    Ui::FormLine *ui;
    widgetPaint* widget;
    int x;
    int y;
    int a;

};

#endif // FORMLINE_H
