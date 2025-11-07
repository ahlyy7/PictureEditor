#pragma once

#ifndef _TGRAPHICSITEMABSTRACT_H_
#define _TGRAPHICSITEMABSTRACT_H_

#include <memory>
#include <QPen>
#include <QBrush>

class QPainter;

class TGraphicsItemAbstract
{
private:
	QPen pen;
	QBrush brush;

protected:
	virtual void drawGrahicsItem(QPainter* painter) const = 0;

public:
	void setPen(const QPen& pen);
	const QPen& getPen() const;

	void setBrush(const QBrush& brush);
	const QBrush& getBrush() const;

	bool tryDrawGrahicesItem(QPainter* painter) const;

	virtual ~TGraphicsItemAbstract() = 0;
};

#endif // !_TGRAPHICSITEMABSTRACT_H_
