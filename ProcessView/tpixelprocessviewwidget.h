#pragma once

#ifndef _TPIXELPROCESSVIEWWIDGET_H_
#define _TPIXELPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TPixelProcessViewWidgetClass; };
QT_END_NAMESPACE

class TPixelProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TPixelProcessViewWidget(QWidget* parent = nullptr);
	~TPixelProcessViewWidget();

	void setValue(int value);
	int getValue();

	void setMinimumValue(int value);
	int getMinimumValue();
	void setMaximumValue(int value);
	int getMaximumValue();

	void setReadOnly(bool readOnly);

signals:
	void valueChanged(int value);

private:
	Ui::TPixelProcessViewWidgetClass* ui;
};

#endif // !_TPIXELPROCESSVIEWWIDGET_H_
