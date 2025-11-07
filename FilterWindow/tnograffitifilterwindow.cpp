#include "ui_tnograffitifilterwindow.h"
#include "tnograffitifilterwindow.h"

TNoGraffitiFilterWindow::TNoGraffitiFilterWindow(QWidget *parent)
	: TGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TNoGraffitiFilterWindowClass())
{
	ui->setupUi(this);
}

TNoGraffitiFilterWindow::~TNoGraffitiFilterWindow()
{
	delete ui;
}

void TNoGraffitiFilterWindow::keyPressEvent(QKeyEvent* event)
{
	TFilterWindowAbstract::keyPressEvent(event);
}

void TNoGraffitiFilterWindow::mousePressEvent(QMouseEvent* event)
{
	TFilterWindowAbstract::mousePressEvent(event);
}

void TNoGraffitiFilterWindow::mouseMoveEvent(QMouseEvent* event)
{
	TFilterWindowAbstract::mouseMoveEvent(event);
}

void TNoGraffitiFilterWindow::mouseReleaseEvent(QMouseEvent* event)
{
	TFilterWindowAbstract::mouseReleaseEvent(event);
}

TGraphicsItemAbstract* TNoGraffitiFilterWindow::createGraphicsItem()
{
	return nullptr;
}

void TNoGraffitiFilterWindow::cancelProcess(const QPoint& beginPointF, const QPoint& cancelPointF)
{
}

void TNoGraffitiFilterWindow::mousePressProcess(const QPoint& pointF)
{
}

void TNoGraffitiFilterWindow::mouseMoveProcess(const QPoint& beginPointF, const QPoint& previousPointF, const QPoint& movePointF)
{
}

void TNoGraffitiFilterWindow::mouseReleaseProcess(const QPoint& beginPointF, const QPoint& endPointF)
{
}
