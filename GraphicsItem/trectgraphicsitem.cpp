#include "pch.h"
#include "trectgraphicsitem.h"
#include <QPainter>

void TRectGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	painter->drawRect(getRect());
}
