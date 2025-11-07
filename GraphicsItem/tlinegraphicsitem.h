#pragma once

#ifndef _TLINEGRAPHICSITEM_H_
#define _TLINEGRAPHICSITEM_H_

#include "tgraphicsitemabstract.h"
#include <QLine>

class TLineGraphicsItem : public TGraphicsItemAbstract
{
private:
	QLine line;

protected:
	// 通过 TGraphicsItemAbstract 继承
	void drawGrahicsItem(QPainter* painter) const override;

public:
	void setLine(const QLine& line);
	void setLine(const QPoint& begin, const QPoint& end);
};

#endif // !_TLINEGRAPHICSITEM_H_
