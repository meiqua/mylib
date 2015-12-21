#ifndef BG22_H
#define BG22_H
#include <QtWidgets>
#include <QtCore/qstate.h>
#include "mainwindow.h"
class Bg22 : public QGraphicsWidget
{
    Q_OBJECT
public:
    Bg22(const QPixmap &pixmap, QGraphicsItem *parent = 0)
        : QGraphicsWidget(parent), _pix(pixmap)
    {
        setAcceptHoverEvents(true);
        setCacheMode(ItemCoordinateCache);
    }

    QRectF boundingRect() const
    {
        return QRectF(0,0,740,390);
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
     QRectF source(0,0,740,390);
     painter->drawPixmap(r,_pix,source);

    }

  QPixmap _pix;
};
#endif // BG22_H
