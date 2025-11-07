#pragma once

#ifndef _TNOFILTERWINDOW_H_
#define _TNOFILTERWINDOW_H_

#include "tfilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNoFilterWindowClass; };
QT_END_NAMESPACE

class TNoFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

protected:
	virtual void paintEvent(QPaintEvent* event) override;

public:
	TNoFilterWindow(QWidget* parent = nullptr);
	~TNoFilterWindow();

private:
	Ui::TNoFilterWindowClass* ui;
};

#endif // !_TNOFILTERWINDOW_H_
