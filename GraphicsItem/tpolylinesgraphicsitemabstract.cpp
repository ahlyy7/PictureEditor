#include "pch.h"
#include "tpolylinesgraphicsitemabstract.h"

void TPolyLinesGraphicsItemAbstract::setPolyLines(QPolygon&& polygon)
{
	this->polygon = polygon;
}

void TPolyLinesGraphicsItemAbstract::setPolyLines(const QPolygon& polygon)
{
	this->polygon = polygon;
}

const QPolygon& TPolyLinesGraphicsItemAbstract::getPolyLines() const
{
	return polygon;
}
