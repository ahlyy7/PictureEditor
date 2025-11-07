#include "getinversecolor.h"

QColor getInverseColor(const QColor& color)
{
	QColor result = color.toHsl();
	int h, s, l, a;
	result.getHsl(&h, &s, &l, &a);
	h = (h + 180) % 360;
	l = 255 - l;
	result.setHsl(h, s, l, a);
	return result;
}
