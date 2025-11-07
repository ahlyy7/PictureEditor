#pragma once

#ifndef _TPOINTPROCESSVIEWWIDGET_H_
#define _TPOINTPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TPointProcessViewWidgetClass; };
QT_END_NAMESPACE

class TPointProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	bool functionSetting;

public:
	TPointProcessViewWidget(QWidget* parent = nullptr);
	~TPointProcessViewWidget();

	void setPoint(const QPointF& point);
	QPointF getPoint();

	void setMaximumPoint(const QPointF& point);
	QPointF getMaximumPoint();

signals:
	void pointChanged(QPointF point);

private:
	Ui::TPointProcessViewWidgetClass* ui;
};

#endif // !_TPOINTPROCESSVIEWWIDGET_H_
