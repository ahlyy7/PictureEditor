#include "pch.h"
#include "ui_tlinegraffitifilterwindow.h"
#include "tlinegraffitifilterwindow.h"
#include "tlinegraphicsitem.h"
#include <QPainter>

void TLineGraffitiFilterWindow::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setWindow({ { 0, 0 }, getImageSize() });

	lineGraphicsItemPainter->tryDrawGrahicesItem(&painter);
}

TLineGraffitiFilterWindow::TLineGraffitiFilterWindow(QWidget *parent)
	: TGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TLineGraffitiFilterWindowClass())
	, lineGraphicsItem(new TLineGraphicsItem())
	, lineGraphicsItemPainter(new TLineGraphicsItem())
{
	ui->setupUi(this);
}

TLineGraffitiFilterWindow::~TLineGraffitiFilterWindow()
{
	delete ui;
}

TGraphicsItemAbstract* TLineGraffitiFilterWindow::createGraphicsItem()
{
	return new TLineGraphicsItem(*lineGraphicsItem);
}

void TLineGraffitiFilterWindow::cancelProcess(const QPoint& beginPoint, const QPoint& cancelPoint)
{
	lineGraphicsItemPainter->setLine({});
	repaint();
}

void TLineGraffitiFilterWindow::mousePressProcess(const QPoint& pointF)
{
	lineGraphicsItemPainter->setPen(getPen());
	lineGraphicsItemPainter->setBrush(getBrush());
	lineGraphicsItem->setPen(getPen());
	lineGraphicsItem->setBrush(getBrush());
}

void TLineGraffitiFilterWindow::mouseMoveProcess(const QPoint& beginPoint, const QPoint& previousPoint, const QPoint& movePoint)
{
	//QPainter painter(this);
	//painter.setWindow({ { 0, 0 }, getImageSize() });

	lineGraphicsItemPainter->setLine(beginPoint, movePoint);
	repaint();
}

void TLineGraffitiFilterWindow::mouseReleaseProcess(const QPoint& beginPoint, const QPoint& endPoint)
{
	lineGraphicsItemPainter->setLine({});
	repaint();

	lineGraphicsItem->setLine(beginPoint, endPoint);
}
