#ifndef BOOKS_H
#define BOOKS_H
#include <QtWidgets>
#include <QtCore/qstate.h>
#include "mainwindow.h"
class Book : public QGraphicsWidget
{
    Q_OBJECT
public:
    Book(const QPixmap &pixmap, QGraphicsItem *parent = 0,qreal startx=0,qreal starty=0,qreal endx=0,qreal endy=0)
        : QGraphicsWidget(parent), _pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
              start.setX(startx);
              start.setY(starty);
              end.setX(endx);
              end.setY(endy);
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, (end.x()-start.x()), (end.y()-start.y()));
    }

    QPainterPath shape() const
    {
        QPainterPath path;
        path.addRect(boundingRect());
        return path;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
    {
        bool down = option->state & QStyle::State_Sunken;
        QRectF r = boundingRect();
        if (down)
            painter->translate(2, 2);
        QRectF source(start.x(),start.y(),(end.x()-start.x()), (end.y()-start.y()));
        painter->drawPixmap(r,_pix,source);
    }

signals:
    void pressed();
    void intofloor();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *)
    {
        emit pressed();
        update();
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
    {
        emit intofloor();
        update();
    }

private:
    QPointF start;
    QPointF end;
    QPixmap _pix;
};
#endif // BOOKS_H
