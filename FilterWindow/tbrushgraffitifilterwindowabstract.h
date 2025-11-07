#pragma once

#ifndef _TBRUSHGRAFFITIFILTERWINDOWABSTRACT_H_
#define _TBRUSHGRAFFITIFILTERWINDOWABSTRACT_H_

#include "tgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TBrushGraffitiFilterWindowAbstractClass; };
QT_END_NAMESPACE

class TBrushGraphicsItemAbstract;

class TBrushGraffitiFilterWindowAbstract : public TGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	std::unique_ptr<TBrushGraphicsItemAbstract> brushGraphicsItem;

	bool cancel;

protected:
	void setBrushGrahicsItem(TBrushGraphicsItemAbstract* brushGraphicsItem);
	TBrushGraphicsItemAbstract* getBrushGrahicsItem() const;

	void cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint) override;
	void mousePressProcess(const QPoint& point) override;
	void mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint) override;
	void mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint) override;

	void paintEvent(QPaintEvent* event) override;

public:
	TBrushGraffitiFilterWindowAbstract(QWidget* parent = nullptr);
	~TBrushGraffitiFilterWindowAbstract();

private:
	Ui::TBrushGraffitiFilterWindowAbstractClass* ui;
};

#endif // !_TBRUSHGRAFFITIFILTERWINDOWABSTRACT_H_
