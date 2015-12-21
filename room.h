#ifndef ROOM_H
#define ROOM_H

#include <QtWidgets>
#include <QtCore/qstate.h>
#include "button.h"
#include <QColor>
class Room : public QGraphicsWidget
{
    Q_OBJECT
public:
    Room(const QPixmap &pixmap, QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent), _pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
    }

    QRectF boundingRect() const
    {
        return QRectF(0, 0, 97, 121);
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
        QRectF source(326,119,87,111);
     painter->drawPixmap(r.adjusted(5,5,-5,-5),_pix,source);

    }

signals:
    void pressed();
    void intoroom();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *)
    {
        emit pressed();
        update();
    }

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)
    {
        emit intoroom();
        update();
    }

private:
            QColor color;
  QPixmap _pix;
};
#endif // ROOM_H
