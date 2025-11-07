#include "ui_tpolylinesgraffitifilterwindow.h"
#include "tpolylinesgraffitifilterwindow.h"
#include "tpolylinesgraphicsitem.h"
#include <QPainter>

void TPolylinesGraffitiFilterWindow::paint(QPainter* painter)
{
	polyLinesGraphicsItemPainter->tryDrawGrahicesItem(painter);
}

TPolylinesGraffitiFilterWindow::TPolylinesGraffitiFilterWindow(QWidget *parent)
	: TPolylinesGraffitiFilterWindowAbstract(parent)
	, ui(new Ui::TPolylinesGraffitiFilterWindowClass())
	, polyLinesGraphicsItemPainter(new TPolyLinesGraphicsItem())
{
	ui->setupUi(this);

	setPolyLinesGraphicsItemPainter(polyLinesGraphicsItemPainter);
}

TPolylinesGraffitiFilterWindow::~TPolylinesGraffitiFilterWindow()
{
	delete ui;
}

TGraphicsItemAbstract* TPolylinesGraffitiFilterWindow::createGraphicsItem()
{
	if (polyLinesGraphicsItemPainter->getPolyLines().size() < 2)
		return nullptr;

	auto polylinesGraphicsItem = new TPolyLinesGraphicsItem(*polyLinesGraphicsItemPainter);

	return polylinesGraphicsItem;
}
