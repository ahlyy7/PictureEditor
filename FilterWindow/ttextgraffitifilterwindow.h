#pragma once

#ifndef _TTEXTGRAFFITIFILTERWINDOW_H_
#define _TTEXTGRAFFITIFILTERWINDOW_H_

#include "tbrushgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TTextGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TTextGraphicsItem;

class TTextGraffitiFilterWindow : public TBrushGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	TTextGraphicsItem* textGraphicsItem;

protected:
	// 通过 TBrushGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;

	void paintEvent(QPaintEvent* event) override;

public:
	TTextGraphicsItem* getTextGraphicsItem();

	TTextGraffitiFilterWindow(QWidget* parent = nullptr);
	~TTextGraffitiFilterWindow();

private:
	Ui::TTextGraffitiFilterWindowClass* ui;
};

#endif // !_TTEXTGRAFFITIFILTERWINDOW_H_
