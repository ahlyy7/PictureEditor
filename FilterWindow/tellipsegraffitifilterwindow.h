#pragma once

#ifndef _TELLIPSEGRAFFITIFILTERWINDOW_H_
#define _TELLIPSEGRAFFITIFILTERWINDOW_H_

#include "tbrushgraffitifilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TEllipseGraffitiFilterWindowClass; };
QT_END_NAMESPACE

class TEllipseGraphicsItem;

class TEllipseGraffitiFilterWindow : public TBrushGraffitiFilterWindowAbstract
{
	Q_OBJECT

private:
	TEllipseGraphicsItem* ellipseGraphicsItem;

protected:
	// 通过 TGraffitiFilterWindowAbstract 继承
	TGraphicsItemAbstract* createGraphicsItem() override;

public:
	TEllipseGraffitiFilterWindow(QWidget* parent = nullptr);
	~TEllipseGraffitiFilterWindow();

private:
	Ui::TEllipseGraffitiFilterWindowClass* ui;
};

#endif // !_TELLIPSEGRAFFITIFILTERWINDOW_H_
