#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>
#include <QtCore/qstate.h>
#include "mainwindow.h"
class Pixmap : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    Pixmap(const QPixmap &pix)
        : QObject(), QGraphicsPixmapItem(pix)
    {
        setCacheMode(ItemCoordinateCache);
    }
};

class Button : public QGraphicsWidget
{
    Q_OBJECT
public:
    Button(const QPixmap &pixmap, QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent), _pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 400, 100);
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
         QRadialGradient grad(r.topLeft(), 100);
        grad.setColorAt(down ? 1 : 0, option->state & QStyle::State_MouseOver ? Qt::white : Qt::lightGray);
        grad.setColorAt(down ? 0 : 1, Qt::gray);
        painter->setPen(Qt::darkGray);
        painter->setBrush(grad);
        painter->drawRect(r);
         QRadialGradient grad2(r.topLeft(), 100);
        grad.setColorAt(down ? 1 : 0, Qt::darkGray);
        grad.setColorAt(down ? 0 : 1, Qt::lightGray);
        painter->setPen(Qt::NoPen);
        painter->setBrush(grad2);
        if (down)
            painter->translate(2, 2);
   //     painter->drawRect(r.adjusted(5, 5, -5, -5));
        QRectF source(0,_pix.height()/6,_pix.width(),_pix.height()*4/6);
        painter->drawPixmap(r.adjusted(5, 5, -5, -5),_pix,source);
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

    QPixmap _pix;
};
#endif
