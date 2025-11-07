#include "pch.h"
#include "tpolylinesgraphicsitem.h"
#include <QPainter>

void TPolyLinesGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	painter->drawPolyline(getPolyLines());
}
