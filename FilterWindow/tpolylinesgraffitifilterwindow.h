#pragma once

#ifndef _TPOLYLINESGRAFFITIFILTERWINDOW_H_
#define _TPOLYLINESGRAFFITIFILTERWINDOW_H_

#include "tpolylinesgraffitifilterwindowabstract.h"
#include <memory>
#include <QPolygon>

QT_BEGIN_NAMESPACE
namespace Ui { class TPolylinesGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TPolyLinesGraphicsItem;

class TPolylinesGraffitiFilterWindow : public TPolylinesGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	TPolyLinesGraphicsItem* polyLinesGraphicsItemPainter;

protected:
	void paint(QPainter* painter) override;

public:
	TPolylinesGraffitiFilterWindow(QWidget* parent = nullptr);
	~TPolylinesGraffitiFilterWindow();

private:
	Ui::TPolylinesGraffitiFilterWindowClass* ui;

protected:
	// 通过 TGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;
};

#endif // !_TPOLYLINESGRAFFITIFILTERWINDOW_H_
