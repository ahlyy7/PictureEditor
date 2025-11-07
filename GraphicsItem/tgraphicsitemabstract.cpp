#include "pch.h"
#include "tgraphicsitemabstract.h"
#include <QPainter>

void TGraphicsItemAbstract::setPen(const QPen& pen)
{
	this->pen = pen;
}

const QPen& TGraphicsItemAbstract::getPen() const
{
	return pen;
}

void TGraphicsItemAbstract::setBrush(const QBrush& brush)
{
	this->brush = brush;
}

const QBrush& TGraphicsItemAbstract::getBrush() const
{
	return brush;
}

bool TGraphicsItemAbstract::tryDrawGrahicesItem(QPainter* painter) const
{
	if (!painter || !painter->device())
		return false;

	painter->setPen(pen);
	painter->setBrush(brush);

	drawGrahicsItem(painter);

	return true;
}

TGraphicsItemAbstract::~TGraphicsItemAbstract()
{
}
