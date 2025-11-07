#pragma once

#ifndef _TINPAINTPROCESSVIEWWIDGETABSTRACT_H_
#define _TINPAINTPROCESSVIEWWIDGETABSTRACT_H_

#include "tprocessviewwidgetabstract.h"
#include <functional>

QT_BEGIN_NAMESPACE
namespace Ui { class TInpaintProcessViewWidgetClass; };
QT_END_NAMESPACE

class TInpaintMaskFunctionAbstract;

class TInpaintProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	std::function<TInpaintMaskFunctionAbstract*()> inpaintMaskFunction;

public:
	TInpaintProcessViewWidget(QWidget* parent = nullptr);
	~TInpaintProcessViewWidget();

	QAction* getUndoAction();
	QAction* getRedoAction();

	TInpaintMaskFunctionAbstract* createInpaintMaskFunction();

	void setInpaintFunction(int inpaintFlag);
	int getInpaintFunction() const;

signals:
	void widthChanged(double width);
	void regionSelectionChanged();
	void inpaintFunctionChanged(int inpaintFlag);

private:
	Ui::TInpaintProcessViewWidgetClass* ui;
};

#endif // !_TINPAINTPROCESSVIEWWIDGETABSTRACT_H_
