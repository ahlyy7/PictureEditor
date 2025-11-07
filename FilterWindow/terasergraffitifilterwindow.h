#pragma once

#ifndef _TERASERGRAFFITIFILTERWINDOW_H_
#define _TERASERGRAFFITIFILTERWINDOW_H_

#include "tpolylinesgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TEraserGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TEraserGraphicsItem;

class TEraserGraffitiFilterWindow : public TPolylinesGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	TEraserGraphicsItem* eraserGraphicsItem;

public:
	TEraserGraffitiFilterWindow(QWidget* parent = nullptr);
	~TEraserGraffitiFilterWindow();

private:
	Ui::TEraserGraffitiFilterWindowClass* ui;

protected:
	// 通过 TPolylinesGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;
	void paint(QPainter* painter) override;
};

#endif // !_TERASERGRAFFITIFILTERWINDOW_H_
