#pragma once

#ifndef _TFORMPROCESSVIEWWIDGET_H_
#define _TFORMPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"
#include <vector>
#include <utility>

QT_BEGIN_NAMESPACE
namespace Ui { class TFormProcessViewWidgetClass; };
QT_END_NAMESPACE

using Mapping = std::pair<QString, QWidget*>;

class TFormProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

public:
	TFormProcessViewWidget(QWidget* parent = nullptr);
	virtual ~TFormProcessViewWidget() override;

	void addForm(const Mapping& mapping);
	void insertForm(const Mapping& mapping, int index);
	void setFormList(const std::vector<Mapping>& mapList);

private:
	Ui::TFormProcessViewWidgetClass* ui;
};

#endif // !_TFORMPROCESSVIEWWIDGET_H_
