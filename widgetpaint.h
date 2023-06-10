#ifndef WIDGETPAINT_H
#define WIDGETPAINT_H

#include <QWidget>

enum FlagPainter{
    SQUARE, LINE, START
};

class widgetPaint : public QWidget
{
    Q_OBJECT
public:
    explicit widgetPaint(QWidget *parent = nullptr);

protected:

    void paintEvent(QPaintEvent*);

    void timerEvent(QTimerEvent*);
signals:

public slots:

    void slotPaintSquare(int x, int y, int a);

    void slotPaint(int x, int y, int a);

    void slotLine(int x, int y, int a);

    void slotStart();

private:
    FlagPainter flag;
    int xSquare;
    int ySquare;
    int aSquare;
    int xLine;
    int yLine;
    int aLine;
    int xStart;
    int aStart;

    bool flagReverse;
    const int TIME = 10;
    const int ASQUARE = 100;
    int time;

};

#endif // WIDGETPAINT_H
