#pragma once

#ifndef _TDRAWOPERATIONFILTERWINDOW_H_
#define _TDRAWOPERATIONFILTERWINDOW_H_

#include "tfilterwindowabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TDrawOperationFilterWindowClass; };
QT_END_NAMESPACE

class TGraffitiFilterWindowAbstract;
class TGraphicsStackFilterWindow;

class TDrawOperationFilterWindow : public TFilterWindowAbstract
{
	Q_OBJECT

private:
	TGraffitiFilterWindowAbstract* graffitiFilterWindow;

	virtual void paintEvent(QPaintEvent* event) override;

public:
	TDrawOperationFilterWindow(QWidget* parent = nullptr);
	~TDrawOperationFilterWindow();

	TGraphicsStackFilterWindow* getGraphicsStackFilterWindow();

	void setGraffitiFilterWindow(TGraffitiFilterWindowAbstract* graffitiFilterWindow);
	TGraffitiFilterWindowAbstract* getGraffitiFilterWindow();

	virtual void setImageSize(QSize imageSize) override;

private slots:
	void graffitiFilterWindowDrawingCompleted(const QPoint& beginPoint, const QPoint& endPoint);

private:
	Ui::TDrawOperationFilterWindowClass* ui;
};

#endif // !_TDRAWOPERATIONFILTERWINDOW_H_
