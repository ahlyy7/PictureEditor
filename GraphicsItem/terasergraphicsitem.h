#pragma once

#ifndef _TERASERGRAPHICSITEM_H_
#define _TERASERGRAPHICSITEM_H_

#include "tpolylinesgraphicsitemabstract.h"

class TEraserGraphicsItem : public TPolyLinesGraphicsItemAbstract
{
protected:
	// 通过 TGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;
};

#endif // !_TERASERGRAPHICSITEM_H_
