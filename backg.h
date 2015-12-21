#ifndef BACKG_H
#define BACKG_H
#include <QtWidgets>
#include <QtCore/qstate.h>
#include "mainwindow.h"
class Bg : public QGraphicsWidget
{
    Q_OBJECT
public:
    Bg(QGraphicsItem *parent = 0,qreal x=0,qreal y=0)
        : QGraphicsWidget(parent)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
        longth=x;
        height=y;
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, longth, height);
    }

    QPainterPath shape() const
    {
        QPainterPath path;
        path.addRect(boundingRect());
        return path;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,  QWidget *)
    {
        QRectF r = boundingRect();
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(3);
     painter->setPen(pen);

     painter->drawRect(r);

    }
private:
    qreal longth;
    qreal height;
};

class Bg0 : public QGraphicsWidget
{
    Q_OBJECT
public:
    Bg0(QPixmap &pixmap,QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent),_pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 255, 298*1.2);
    }

    QPainterPath shape() const
    {
        QPainterPath path;
        path.addRect(boundingRect());
        return path;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem * ,  QWidget *)
    {
        QRectF r = boundingRect();
QRectF source=QRectF(107,65,255,298);
//        painter->scale(1,1.5);
     painter->drawPixmap(r,_pix,source);

    }
private:
QPixmap _pix;
};
#endif // BACKG_H
