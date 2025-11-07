#pragma once

#ifndef _TPROCESSVIEWWIDGETABSTRACT_H_
#define _TPROCESSVIEWWIDGETABSTRACT_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ProcessViewWidgetAbstractClass; };
QT_END_NAMESPACE

class TProcessViewWidgetAbstract : public QWidget
{
	Q_OBJECT

public:
	TProcessViewWidgetAbstract(QWidget* parent = nullptr);
	virtual ~TProcessViewWidgetAbstract() = 0;

private:
	Ui::ProcessViewWidgetAbstractClass* ui;
};

#endif // !_TPROCESSVIEWWIDGETABSTRACT_H_
