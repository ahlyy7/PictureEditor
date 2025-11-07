#pragma once

#ifndef _TRECTPROCESSVIEWWIDGET_H_
#define _TRECTPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TRectProcessViewWidgetClass; };
QT_END_NAMESPACE

class TRectProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	QRect rect;
	bool settingRect;

public:
	TRectProcessViewWidget(QWidget* parent = nullptr);
	~TRectProcessViewWidget();

	void setX(int x);
	int getX();

	void setY(int y);
	int getY();

	void setWidth(int width);
	int getWidth();

	void setMaximumWidth(int maximumWidth);
	int getMaximumWidth();

	void setMinimumWidth(int minimumWidth);
	int getMinimumWidth();

	void setHeight(int height);
	int getHeight();

	void setMaximumHeight(int maximumHeight);
	int getMaximumHeight();

	void setMinimumHeight(int minimumHeight);
	int getMinimumHeight();

	void setRect(const QRect& rect);
	QRect getRect();

signals:
	void xChanged(int x);
	void yChanged(int y);
	void widthChanged(int width);
	void heightChanged(int height);
	void rectChanged(QRect rect);

private:
	Ui::TRectProcessViewWidgetClass* ui;
};

#endif // !_TRECTPROCESSVIEWWIDGET_H_
