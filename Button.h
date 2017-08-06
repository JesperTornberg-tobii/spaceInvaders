#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructors
    Button(QString name, QGraphicsItem* parent=NULL);

    // methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    // no need to define this, all the logic is taken care of by the SLOT it
    // is connected to when it is emitted
    void clicked();

private:
    QGraphicsTextItem *text;

};

#endif // BUTTON_H
