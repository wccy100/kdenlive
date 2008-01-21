/***************************************************************************
 *   Copyright (C) 2007 by Jean-Baptiste Mardelle (jb@kdenlive.org)        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/


#include <QPainter>
#include <QStyleOptionGraphicsItem>

#include <KDebug>


#include "labelitem.h"

LabelItem::LabelItem(QString text, QGraphicsRectItem *parent)
    : QGraphicsSimpleTextItem(" " + text + " ", parent)
{
  //setParentItem(parent); 
  setFlags(QGraphicsItem::ItemIgnoresTransformations);
}

int LabelItem::type () const
{
  return 70001;
}

// virtual 

 void LabelItem::paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget)
 {
    //painter->setClipRect( option->exposedRect );
    QRectF rep = option->exposedRect;
    QGraphicsRectItem *parent = (QGraphicsRectItem *) parentItem();
    QRectF par = mapFromScene(parent->rect()).boundingRect();
    //kDebug()<<"REPAINT RECT: "<<par.width();
    //kDebug()<<"REPAINT RECT: "<<rep.x()<<", "<<rep.y()<<", "<<rep.width()<<", "<<rep.height();
    //kDebug()<<"PARENT RECT: "<<par.x()<<", "<<par.y()<<", "<<par.width()<<", "<<par.height();
    QRectF parrect = parent->rect();
    //QRectF transRect = deviceTransform(view->viewportTransform()).inverted().mapRect(parrect);
    painter->setClipRect( par);
    //painter->fillRect(rect(), Qt::red);
    QPainterPath path;
    path.addRoundRect(boundingRect(), 40);
    //painter->fillPath(path, QColor(200, 100, 200, 150));
    //painter->setClipPath(path);
    painter->fillPath(path, QColor(200, 200, 200, 100));
    painter->drawText(boundingRect(), Qt::AlignCenter, text());
    //painter->drawRect(rect());
    //painter->drawRoundRect(-10, -10, 20, 20);
 }

#include "labelitem.moc"
