#include "ui_tellipsegraffitifilterwindow.h"
#include "tellipsegraffitifilterwindow.h"
#include "tellipsegraphicsitem.h"

TEllipseGraffitiFilterWindow::TEllipseGraffitiFilterWindow(QWidget *parent)
	: TBrushGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TEllipseGraffitiFilterWindowClass())
	, ellipseGraphicsItem(new TEllipseGraphicsItem())
{
	ui->setupUi(this);

	setBrushGrahicsItem(ellipseGraphicsItem);
}

TEllipseGraffitiFilterWindow::~TEllipseGraffitiFilterWindow()
{
	delete ui;
}

TGraphicsItemAbstract* TEllipseGraffitiFilterWindow::createGraphicsItem()
{
	return new TEllipseGraphicsItem(*ellipseGraphicsItem);
}
