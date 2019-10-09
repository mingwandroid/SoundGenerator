/*
 * Copyright 2019 Benoit Pelletier
 *
 * This file is part of Sound Generator.
 *
 * Sound Generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sound Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sound Generator.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#ifndef LINKITEM_H
#define LINKITEM_H

//#include <QWidget>
#include <QGraphicsItem>
#include "types.h"

class PinItem;

class LinkItem : public QGraphicsItem
{
public:
    enum { Type = UserType + LINK_TYPE };
    int type() const override { return Type; }

    LinkItem(QGraphicsItem *parent = nullptr);
    //virtual ~LinkItem() override;

    void setPenStyle(Qt::PenStyle penStyle) { m_penStyle = penStyle; }
    void setPenSize(int size) { m_size = size; }
    int penSize() { return m_size; }

    void setMousePos(QPointF mousePos);
    QPointF mousePos() { return m_mousePos; }

    void setFirstPin(PinItem* pin);
    void setSecondPin(PinItem* pin);
    PinItem* firstPin() { return m_pinA; }
    PinItem* secondPin() { return m_pinB; }

    PinItem* getPinThatIsNot(PinItem* pin);

    void unlink();

    void prepareChange();

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* widget) override;
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
private:

    int m_size;
    Qt::PenStyle m_penStyle;
    PinItem* m_pinA;
    PinItem* m_pinB;

    QPointF m_mousePos;
};

#endif // LINKITEM_H
