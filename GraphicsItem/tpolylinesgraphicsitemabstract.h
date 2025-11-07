#pragma once

#ifndef _TPOLYLINESGRAPHICSITEMABSTRACT_H_
#define _TPOLYLINESGRAPHICSITEMABSTRACT_H_

#include "tgraphicsitemabstract.h"
#include <QPolygon>

class TPolyLinesGraphicsItemAbstract : public TGraphicsItemAbstract
{
private:
	QPolygon polygon;

public:
	void setPolyLines(QPolygon&& polygon);
	void setPolyLines(const QPolygon& polygon);

	const QPolygon& getPolyLines() const;
};

#endif // !_TPOLYLINESGRAPHICSITEMABSTRACT_H_
