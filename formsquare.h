#ifndef FORMSQUARE_H
#define FORMSQUARE_H

#include <QWidget>
#include "widgetpaint.h"

namespace Ui {
class FormSquare;
}

class FormSquare : public QWidget
{
    Q_OBJECT

public:
    explicit FormSquare(QWidget *parent = nullptr);
    ~FormSquare();

signals:

    void signalSquare(int x, int y, int a);

    void signalPaintSquare(int x, int y, int a);

public slots:



private slots:
    void on_horizontalScrollBarX_valueChanged(int value);

    void on_horizontalScrollBarY_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_pushGenerate_clicked();

private:
    widgetPaint* paintSquare;
    Ui::FormSquare *ui;
    int x;
    int y;
    int a;
};

#endif // FORMSQUARE_H
