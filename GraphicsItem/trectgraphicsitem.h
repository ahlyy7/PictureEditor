#pragma once

#ifndef _TRECTGRAPHICSITEM_H_
#define _TRECTGRAPHICSITEM_H_

#include "tbrushgraphicsitemabstract.h"

class TRectGraphicsItem : public TBrushGraphicsItemAbstract
{
protected:
	// 通过 TGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;
};

#endif // !_TRECTGRAPHICSITEM_H_
