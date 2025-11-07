#pragma once

#ifndef _TPOLYLINESGRAPHICSITEM_H_
#define _TPOLYLINESGRAPHICSITEM_H_

#include "tpolylinesgraphicsitemabstract.h"

class TPolyLinesGraphicsItem : public TPolyLinesGraphicsItemAbstract
{
protected:
	// 通过 TGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;
};

#endif // !_TPOLYLINESGRAPHICSITEM_H_
