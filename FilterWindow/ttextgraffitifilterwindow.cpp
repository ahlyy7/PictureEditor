#include "ui_ttextgraffitifilterwindow.h"
#include "ttextgraffitifilterwindow.h"
#include "ttextgraphicsitem.h"
#include <QPainter>
#include "getinversecolor.h"
#include <qevent.h>

TTextGraphicsItem* TTextGraffitiFilterWindow::getTextGraphicsItem()
{
	return textGraphicsItem;
}

TTextGraffitiFilterWindow::TTextGraffitiFilterWindow(QWidget *parent)
	: TBrushGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TTextGraffitiFilterWindowClass())
	, textGraphicsItem(new TTextGraphicsItem())
{
	ui->setupUi(this);

	setBrushGrahicsItem(textGraphicsItem);
}

TTextGraffitiFilterWindow::~TTextGraffitiFilterWindow()
{
	delete ui;
}

TGraphicsItemAbstract* TTextGraffitiFilterWindow::createGraphicsItem()
{
	return new TTextGraphicsItem(*textGraphicsItem);
}

void TTextGraffitiFilterWindow::paintEvent(QPaintEvent* event)
{
	event->ignore();
	TBrushGraffitiFilterWindowAbstract::paintEvent(event);

	if (!event->isAccepted())
	{
		event->accept();
		return;
	}

	QPainter painter(this);
	painter.setWindow({ { 0, 0 }, getImageSize() });

	QPen pen = getPen();
	pen.setWidth(0);
	pen.setStyle(Qt::DashLine);
	pen.setColor(getInverseColor(pen.color()));
	painter.setPen(pen);

	painter.drawRect(textGraphicsItem->getRect());
}
