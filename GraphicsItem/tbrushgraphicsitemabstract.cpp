#include "pch.h"
#include "tbrushgraphicsitemabstract.h"

TBrushGraphicsItemAbstract::~TBrushGraphicsItemAbstract()
{}

void TBrushGraphicsItemAbstract::setRect(const QRect& rect)
{
	this->rect = rect;
}

const QRect& TBrushGraphicsItemAbstract::getRect() const
{
	return rect;
}
