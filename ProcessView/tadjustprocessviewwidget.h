#pragma once

#ifndef _TADJUSTPROCESSVIEWWIDGET_H_
#define _TADJUSTPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TAdjustProcessViewWidgetClass; };
QT_END_NAMESPACE

class TAdjustProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TAdjustProcessViewWidget(QWidget* parent = nullptr);
	~TAdjustProcessViewWidget();

	void setAdjust(int adjustValue);
	int getAdjust();

signals:
	void adjustChanged(int adjustValue);

private:
	Ui::TAdjustProcessViewWidgetClass* ui;
};

#endif // !_TADJUSTPROCESSVIEWWIDGET_H_
