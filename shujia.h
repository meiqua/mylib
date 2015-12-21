#ifndef SHUJIA_H
#define SHUJIA_H

#include <QtWidgets>
#include <QtCore/qstate.h>
#include "mainwindow.h"
#include "button.h"
#include <QVector>
class Shujia : public QGraphicsWidget
{
    Q_OBJECT
public:
    Shujia(const QPixmap &pixmap, QGraphicsItem *parent = 0,
           QPointF p1=QPointF(0,0),QPointF p2=QPointF(0,0),QPointF p3=QPointF(0,0),
           QPointF p4=QPointF(0,0),QPointF p5=QPointF(0,0),QPointF p6=QPointF(0,0))
        : QGraphicsWidget(parent), _pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
        QVector<QPointF> vec;
        vec.append(p1);
        vec.append(p2);
        vec.append(p3);
        vec.append(p4);
        vec.append(p5);
        vec.append(p6);
        QPolygonF pol=QPolygonF(vec);
        path.addPolygon(pol);
    }

    QRectF boundingRect() const
    {
        return path.boundingRect();
    }

    QPainterPath shape() const
    {
        return path;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
    {
        bool down = option->state & QStyle::State_Sunken;
        bool over =  option->state & QStyle::State_MouseOver;
        QRectF r = boundingRect();
        painter->drawPixmap(r,_pix,path.boundingRect());

        if ( over)
        {
            QPen pen1;
            pen1.setColor(Qt::green);
            pen1.setWidth(5);
         painter->setPen(pen1);
            painter->drawPath(path);
        }
            if (down)
            {
                QPen pen2;
                pen2.setColor(Qt::yellow);
                pen2.setWidth(5);
             painter->setPen(pen2);
                painter->drawPath(path);
            }
//        QRectF source(0,0,1300,624);




    }
signals:
    void pressed();
    void intoshujia();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *)
    {
        emit pressed();
        update();
    }
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
    {
        emit intoshujia();
        update();
    }
private:

    QPixmap _pix;
    QPainterPath  path;

};
#endif // SHUJIA_H



