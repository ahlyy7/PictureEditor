#include "pch.h"
#include "terasergraphicsitem.h"
#include <QPainter>

void TEraserGraphicsItem::drawGrahicsItem(QPainter* painter) const
{
	auto compositionMode = painter->compositionMode();
	painter->setCompositionMode(QPainter::CompositionMode_Clear);

	painter->drawPolyline(getPolyLines());

	painter->setCompositionMode(compositionMode);
}
