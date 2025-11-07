#pragma once

#ifndef _TTHRESHPROCESSVIEWWIDGET_H_
#define _TTHRESHPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TThreshProcessViewWidgetClass; };
QT_END_NAMESPACE

class TThreshProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TThreshProcessViewWidget(QWidget* parent = nullptr);
	~TThreshProcessViewWidget();

	void setThresh(int thresh);
	int getThresh();

signals:
	void threshChanged(int thresh);

private:
	Ui::TThreshProcessViewWidgetClass* ui;
};

#endif // !_TTHRESHPROCESSVIEWWIDGET_H_
