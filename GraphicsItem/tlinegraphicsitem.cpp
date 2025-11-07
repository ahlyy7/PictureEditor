#include "pch.h"
#include "tlinegraphicsitem.h"
#include <QPainter>

void TLineGraphicsItem::setLine(const QLine& line)
{
	this->line = line;
}

void TLineGraphicsItem::setLine(const QPoint& begin, const QPoint& end)
{
	line = { begin, end };
}

void TLineGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	painter->drawLine(line);
}
