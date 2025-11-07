#pragma once

#ifndef _TSIZEPROCESSVIEWWIDGET_H_
#define _TSIZEPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TSizeProcessViewWidgetClass; };
QT_END_NAMESPACE

class QSpinBox;

class TSizeProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	QSpinBox* widthSpinBox;
	QSpinBox* heightSpinBox;

	bool equal;

public:
	TSizeProcessViewWidget(QWidget* parent = nullptr);
	virtual ~TSizeProcessViewWidget() override;

	void setWidth(int width);
	int getWidth();

	void setHeight(int height);
	int getHeight();

	void setSize(QSize size);
	QSize getSize();

	void setMinimumWidth(int width);
	int getMinimumWidth();
	void setMaximumWidth(int width);
	int getMaximumWidth();

	void setMinimumHeight(int height);
	int getMinimumHeight();
	void setMaximumHeight(int height);
	int getMaximumHeight();

	void setMinimumSize(QSize size);
	QSize getMinimumSize();
	void setMaximumSize(QSize size);
	QSize getMaximumSize();

	void setReadOnly(bool readOnly);

	void setWidthAndHeightEqual(bool equal);

	void setSingleStep(QSize singleStep);
	void setWidthSingleStep(int singleStep);
	void setHeightSingleStep(int singleStep);

signals:
	void widthChanged(int width);
	void heightChanged(int height);

private:
	Ui::TSizeProcessViewWidgetClass* ui;
};

#endif // !_TSIZEPROCESSVIEWWIDGET_H_
