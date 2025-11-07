#include "ui_tdrawoperationfilterwindow.h"
#include "tdrawoperationfilterwindow.h"
#include "tgraffitifilterwindowabstract.h"
#include "tgraphicsitemabstract.h"
#include <qevent.h>

void TDrawOperationFilterWindow::paintEvent(QPaintEvent* event)
{
	if (graffitiFilterWindow)
		graffitiFilterWindow->setGeometry(ui->graphicsStackFilterWindow->geometry());

	event->accept();
}

TDrawOperationFilterWindow::TDrawOperationFilterWindow(QWidget *parent)
	: TFilterWindowAbstract(parent)
	, ui(new Ui::TDrawOperationFilterWindowClass())
	, graffitiFilterWindow(nullptr)
{
	ui->setupUi(this);
}

TDrawOperationFilterWindow::~TDrawOperationFilterWindow()
{
	delete ui;
}

TGraphicsStackFilterWindow* TDrawOperationFilterWindow::getGraphicsStackFilterWindow()
{
	return ui->graphicsStackFilterWindow;
}

void TDrawOperationFilterWindow::setGraffitiFilterWindow(TGraffitiFilterWindowAbstract* graffitiFilterWindow)
{
	if (this->graffitiFilterWindow == graffitiFilterWindow)
		return;

	delete this->graffitiFilterWindow;

	if (!graffitiFilterWindow)
		return;

	this->graffitiFilterWindow = graffitiFilterWindow;
	graffitiFilterWindow->setParent(this);
	graffitiFilterWindow->raise();
	graffitiFilterWindow->show();

	graffitiFilterWindow->setImageSize(getImageSize());
	connect(graffitiFilterWindow, &TGraffitiFilterWindowAbstract::mouseReleased, this, &TDrawOperationFilterWindow::graffitiFilterWindowDrawingCompleted);
}

TGraffitiFilterWindowAbstract* TDrawOperationFilterWindow::getGraffitiFilterWindow()
{
	return graffitiFilterWindow;
}

void TDrawOperationFilterWindow::setImageSize(QSize imageSize)
{
	TFilterWindowAbstract::setImageSize(imageSize);

	ui->graphicsStackFilterWindow->setImageSize(imageSize);
	if (graffitiFilterWindow)
		graffitiFilterWindow->setImageSize(imageSize);
}

void TDrawOperationFilterWindow::graffitiFilterWindowDrawingCompleted(const QPoint& beginPoint, const QPoint& endPoint)
{
	Q_UNUSED(beginPoint);
	Q_UNUSED(endPoint);

	auto graphicsItem = graffitiFilterWindow->tryCreateGraphicsItem();
	if (!graphicsItem)
		return;

	ui->graphicsStackFilterWindow->pushGraphicsItem(graphicsItem);
}
