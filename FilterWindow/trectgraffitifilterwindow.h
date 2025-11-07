#pragma once

#ifndef _TRECTGRAFFITIFILTERWINDOW_H_
#define _TRECTGRAFFITIFILTERWINDOW_H_

#include "tbrushgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TRectGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TRectGraphicsItem;

class TRectGraffitiFilterWindow : public TBrushGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	TRectGraphicsItem* rectGraphicsItem;

	bool cancel;

protected:
	// 通过 TGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;

public:
	TRectGraffitiFilterWindow(QWidget* parent = nullptr);
	~TRectGraffitiFilterWindow();

private:
	Ui::TRectGraffitiFilterWindowClass* ui;
};

#endif // !_TRECTGRAFFITIFILTERWINDOW_H_
