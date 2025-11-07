#pragma once

#ifndef _TNOPROCESSVIEWWIDGET_H_
#define _TNOPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNoProcessViewWidgetClass; };
QT_END_NAMESPACE

class TNoProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TNoProcessViewWidget(QWidget* parent = nullptr);
	~TNoProcessViewWidget();

	void setText(const QString& text);
	QString text();

private:
	Ui::TNoProcessViewWidgetClass* ui;
};

#endif // !_TNOPROCESSVIEWWIDGET_H_
