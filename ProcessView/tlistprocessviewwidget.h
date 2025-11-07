#pragma once

#ifndef _TLISTPROCESSVIEWWIDGET_H_
#define _TLISTPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class TListProcessViewWidgetClass; };
QT_END_NAMESPACE

class TListProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TListProcessViewWidget(QWidget* parent = nullptr);
	~TListProcessViewWidget();

	int count();

	void clearProcessViewWidget();
	void addProcessViewWidget(QWidget* processViewWidget);
	void insertProcessViewWidget(QWidget* processViewWidget, int index);
	void setProcessViewWidgetList(const std::vector<QWidget*>& processViewWidgetList);

private:
	Ui::TListProcessViewWidgetClass* ui;
};

#endif // !_TLISTPROCESSVIEWWIDGET_H_
