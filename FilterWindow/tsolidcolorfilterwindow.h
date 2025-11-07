#pragma once

#ifndef _TNORMALFILTERWINDOW_H_
#define _TNORMALFILTERWINDOW_H_

#include "tfilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TNormalFilterWindowClass; };
QT_END_NAMESPACE

class TSolidColorFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	int red;
	int green;
	int blue;
	int alpha;

protected:
	virtual void paintEvent(QPaintEvent* event) override;

public:
	void setRgb(int red, int green, int blue, int alpha = 255);
	void setAlpha(int alpha);

	TSolidColorFilterWindow(QWidget* parent = nullptr);
	virtual ~TSolidColorFilterWindow() override;

private:
	Ui::TNormalFilterWindowClass* ui;
};

#endif // !_TNORMALFILTERWINDOW_H_
