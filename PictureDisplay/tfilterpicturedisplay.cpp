#include "ui_tfilterpicturedisplay.h"
#include "tfilterpicturedisplay.h"
#include "tfilterwindowabstract.h"
#include <QVBoxLayout>

TFilterPictureDisplay::TFilterPictureDisplay(QWidget *parent)
	: TMultilayerPictureDisplayAbstract(parent)
	, ui(new Ui::TFilterPictureDisplayClass())
	, after(nullptr)
	, before(nullptr)
{
	ui->setupUi(this);
}

TFilterPictureDisplay::~TFilterPictureDisplay()
{
	delete ui;
}

void TFilterPictureDisplay::reZorder()
{
	if (!after || !before)
		return;

	after->stackUnder(before);
}

void TFilterPictureDisplay::paintEvent(QPaintEvent* event)
{
	QSize size = this->size();
	QSize pixmapSize = after->getPixmapSize();
	size -= pixmapSize;
	size /= 2;

	QRect rect({ size.width(), size.height() }, pixmapSize);

	before->setGeometry(rect);
}

void TFilterPictureDisplay::setPictureDisplayWidget(TPictureDisplayAbstract* widget)
{
	TMultilayerPictureDisplayAbstract::setPictureDisplayWidget(widget);

	after = widget;

	reZorder();
}

//void TFilterPictureDisplay::setAfterPictureDisplay(TPictureDisplayAbstract* after)
//{
//	if (this->after == after)
//		return;
//
//	delete this->after;
//
//	after->setParent(this);
//	layout()->addWidget(after);
//
//	this->after = after;
//	reZorder();
//}

void TFilterPictureDisplay::setBeforeFilterWindow(TFilterWindowAbstract* before)
{
	if (this->before == before)
		return;

	delete this->before;

	before->setParent(this);
	before->show();

	this->before = before;
	reZorder();
}

TFilterWindowAbstract* TFilterPictureDisplay::getBeforeFilterWindow() const
{
	return before;
}

void TFilterPictureDisplay::setPixmap(const QPixmap& pixmap)
{
	after->setPixmap(pixmap);

	//filterSize = pixmap.size();
	//setMinimumSize(filterSize);
}

QSize TFilterPictureDisplay::getPixmapSize()
{
	return after ? after->getPixmapSize() : QSize(0, 0);
}
