#pragma once

#ifndef _TPOLYLINESGRAFFITIFILTERWINDOWABSTRACT_H_
#define _TPOLYLINESGRAFFITIFILTERWINDOWABSTRACT_H_

#include "tgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TPolylinesGraffitiFilterWindowAbstractClass; };
QT_END_NAMESPACE

class TPolyLinesGraphicsItemAbstract;

class TPolylinesGraffitiFilterWindowAbstract : public TGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	std::unique_ptr<TPolyLinesGraphicsItemAbstract> polyLinesGraphicsItemPainter;
	QPolygon polylinesPainter;
	bool isOver;

protected:
	void setPolyLinesGraphicsItemPainter(TPolyLinesGraphicsItemAbstract* polyLinesGraphicsItemPainter);

	void paintEvent(QPaintEvent* event) override;

	virtual void paint(QPainter* painter) = 0;

public:
	TPolyLinesGraphicsItemAbstract* getPolyLinesGraphicsItemPainter() const;

	TPolylinesGraffitiFilterWindowAbstract(QWidget* parent = nullptr);
	~TPolylinesGraffitiFilterWindowAbstract();

protected:
	void cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint) override;
	void mousePressProcess(const QPoint& point) override;
	void mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint) override;
	void mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint) override;

private:
	Ui::TPolylinesGraffitiFilterWindowAbstractClass* ui;
};

#endif // !_TPOLYLINESGRAFFITIFILTERWINDOWABSTRACT_H_
