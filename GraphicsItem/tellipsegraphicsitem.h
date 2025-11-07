#pragma once

#ifndef _TELLIPSEGRAPHICSITEM_H_
#define _TELLIPSEGRAPHICSITEM_H_

#include "tbrushgraphicsitemabstract.h"

class TEllipseGraphicsItem : public TBrushGraphicsItemAbstract
{
protected:
	// 通过 TBrushGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;
};

#endif // !_TELLIPSEGRAPHICSITEM_H_
