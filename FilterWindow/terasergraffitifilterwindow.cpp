#include "ui_terasergraffitifilterwindow.h"
#include "terasergraffitifilterwindow.h"
#include "terasergraphicsitem.h"
#include <QPainter>
#include "getinversecolor.h"

TEraserGraffitiFilterWindow::TEraserGraffitiFilterWindow(QWidget *parent)
	: TPolylinesGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TEraserGraffitiFilterWindowClass())
	, eraserGraphicsItem(new TEraserGraphicsItem())
{
	ui->setupUi(this);

	setPolyLinesGraphicsItemPainter(eraserGraphicsItem);
}

TEraserGraffitiFilterWindow::~TEraserGraffitiFilterWindow()
{
	delete ui;
}

TGraphicsItemAbstract* TEraserGraffitiFilterWindow::createGraphicsItem()
{
	return new TEraserGraphicsItem(*eraserGraphicsItem);
}

void TEraserGraffitiFilterWindow::paint(QPainter* painter)
{
	//	pen
	QPen pen = getPen();

	QColor color = pen.color();
	color.setAlpha(128);

	QColor inverseColor(getInverseColor(color));

	auto width = pen.widthF();

	auto inverseWidth = width * 1.25;

	pen.setColor(inverseColor);
	pen.setWidthF(inverseWidth);
	painter->setPen(pen);
	painter->drawPolyline(eraserGraphicsItem->getPolyLines());



	pen.setColor(color);
	pen.setWidthF(width);
	painter->setPen(pen);
	painter->drawPolyline(eraserGraphicsItem->getPolyLines());
}
