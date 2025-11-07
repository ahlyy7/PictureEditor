#include "ui_tgraphicsstackfilterwindow.h"
#include "tgraphicsstackfilterwindow.h"
#include <qevent.h>
#include <QPainter>

void TGraphicsStackFilterWindow::setCurrentIndex(size_t index)
{
	if (currentIndex == index)
		return;

	auto oldCurrentIndex = currentIndex;
	currentIndex = index;

	repaint();

	auto size = graphicsItems.size();

	//if (index == 0)
	//	emit emptyed(true);
	//else if (oldCurrentIndex == 0)
	//	emit emptyed(false);

	if (index == 0)
		emit arrivedBack(true);
	else if (oldCurrentIndex == 0)
		emit arrivedBack(false);

	if (index == size)
		emit arrivedFront(true);
	else if (oldCurrentIndex == size)
		emit arrivedFront(false);

	emit currentGraphicsItemChanged(index);
}

void TGraphicsStackFilterWindow::paintGraphicsItems(QPaintDevice* paintDevice)
{
	auto size = getImageSize();

	//	pixmap

	pixmap.fill({ 0, 0, 0, 0 });
	QPainter painter(&pixmap);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setRenderHint(QPainter::TextAntialiasing, true);
	painter.setFont(font());
	//painter.setWindow({ { 0, 0 }, getImageSize() });

	std::for_each_n(graphicsItems.cbegin(), currentIndex, [&painter](const auto& graphicsItem)
		{
			graphicsItem->tryDrawGrahicesItem(&painter);
		});

	painter.end();



	//	paintDevice
	painter.begin(paintDevice);
	painter.setWindow({ { 0, 0 }, size });

	painter.drawPixmap(0, 0, pixmap);
}

void TGraphicsStackFilterWindow::paintEvent(QPaintEvent* event)
{
	paintGraphicsItems(this);

	event->accept();
}

std::pair<std::vector<std::unique_ptr<TGraphicsItemAbstract>>::const_iterator, std::vector<std::unique_ptr<TGraphicsItemAbstract>>::const_iterator> TGraphicsStackFilterWindow::getGraphicsItems() const
{
	return { graphicsItems.cbegin(), graphicsItems.cbegin() + currentIndex };
}

void TGraphicsStackFilterWindow::clear()
{
	graphicsItems.clear();
	setCurrentIndex(0);
}

void TGraphicsStackFilterWindow::setImageSize(QSize imageSize)
{
	TFilterWindowAbstract::setImageSize(imageSize);

	pixmap = QPixmap(imageSize);
}

void TGraphicsStackFilterWindow::pushGraphicsItem(TGraphicsItemAbstract* graphicsItem)
{
	graphicsItems.resize(currentIndex + 1);
	graphicsItems.back().reset(graphicsItem);

	setCurrentIndex(currentIndex + 1);
}

void TGraphicsStackFilterWindow::fallbackGraphicsItem()
{
	setCurrentIndex(currentIndex - 1);
}

void TGraphicsStackFilterWindow::forwardGraphicsItem()
{
	setCurrentIndex(currentIndex + 1);
}

TGraphicsStackFilterWindow::TGraphicsStackFilterWindow(QWidget *parent)
	: TFilterWindowAbstract(parent)
	, ui(new Ui::TGraphicsFilterWindowClass())
	, currentIndex(0ULL)
{
	ui->setupUi(this);
}

TGraphicsStackFilterWindow::~TGraphicsStackFilterWindow()
{
	delete ui;
}

size_t TGraphicsStackFilterWindow::getCurrentSize()
{
	return currentIndex;
}
