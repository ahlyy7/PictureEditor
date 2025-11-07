#pragma once

#ifndef _TBRUSHGRAPHICSITEMABSTRACT_H_
#define _TBRUSHGRAPHICSITEMABSTRACT_H_

#include "tgraphicsitemabstract.h"

class TBrushGraphicsItemAbstract : public TGraphicsItemAbstract
{
private:
	QRect rect;

public:
	virtual ~TBrushGraphicsItemAbstract() override = 0;

	void setRect(const QRect& rect);
	const QRect& getRect() const;
};

#endif // !_TBRUSHGRAPHICSITEMABSTRACT_H_
