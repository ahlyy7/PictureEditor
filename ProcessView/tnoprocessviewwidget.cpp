#include "ui_tnoprocessviewwidget.h"
#include "tnoprocessviewwidget.h"

TNoProcessViewWidget::TNoProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TNoProcessViewWidgetClass())
{
	ui->setupUi(this);
}

TNoProcessViewWidget::~TNoProcessViewWidget()
{
	delete ui;
}

void TNoProcessViewWidget::setText(const QString& text)
{
	ui->label->setText(text);
}

QString TNoProcessViewWidget::text()
{
	return ui->label->text();
}
