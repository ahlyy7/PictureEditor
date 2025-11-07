#include "pch.h"
#include "tellipsegraphicsitem.h"
#include <QPainter>

void TEllipseGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	painter->drawEllipse(getRect());
}
