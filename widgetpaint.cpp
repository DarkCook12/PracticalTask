#include "widgetpaint.h"
#include "QPainter"

widgetPaint::widgetPaint(QWidget *parent) : QWidget(parent)
{


    xSquare = 0;
    ySquare = 0;
    aSquare = 0;
    flag = SQUARE;

    xLine = 0;
    yLine = 0;
    aLine = 0;

    flagReverse = false;
}

void widgetPaint::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    if(flag == SQUARE){
        painter.drawRect(xSquare, ySquare, aSquare, aSquare);
    }
    if(flag == LINE){
        painter.drawLine(xLine, yLine, xLine+aLine, yLine);
    }
    if(flag == START){
        if (xStart<=xLine + aLine){

            painter.drawRect(xStart, yLine, aStart, aStart);

            xStart++;
            aStart++;
        }
        else
            killTimer(time);
    }
    painter.end();

}

void widgetPaint::timerEvent(QTimerEvent *)
{
    repaint();
}

void widgetPaint::slotPaintSquare(int x, int y, int a)
{
    xSquare = x;
    ySquare = y;
    aSquare = a;
    flag = SQUARE;
    repaint();
}

void widgetPaint::slotPaint(int x, int y, int a)
{
    xSquare = x;
    ySquare = y;
    aSquare = a;
    flag = SQUARE;
    repaint();
}

void widgetPaint::slotLine(int x, int y, int a)
{
    xLine = x;
    yLine = y;
    aLine = a;
    flag = LINE;
    repaint();
}

void widgetPaint::slotStart()
{
    time = startTimer(TIME);
    xStart = xLine;
    aStart = aSquare;
    flag = START;
}
