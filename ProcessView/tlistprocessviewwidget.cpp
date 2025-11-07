#include "ui_tlistprocessviewwidget.h"
#include "tlistprocessviewwidget.h"

TListProcessViewWidget::TListProcessViewWidget(QWidget *parent)
	: TProcessViewWidgetAbstract(parent)
	, ui(new Ui::TListProcessViewWidgetClass())
{
	ui->setupUi(this);
}

TListProcessViewWidget::~TListProcessViewWidget()
{
	delete ui;
}

int TListProcessViewWidget::count()
{
	return ui->verticalLayout->count() - 1;
}

void TListProcessViewWidget::clearProcessViewWidget()
{
	for (auto widget : findChildren<QWidget*>(Qt::FindDirectChildrenOnly))
		delete widget;
}

void TListProcessViewWidget::addProcessViewWidget(QWidget* processViewWidget)
{
	processViewWidget->setParent(this);
	ui->verticalLayout->insertWidget(count(), processViewWidget);
}

void TListProcessViewWidget::insertProcessViewWidget(QWidget* processViewWidget, int index)
{
	index = std::clamp(index, 0, count());

	processViewWidget->setParent(this);
	ui->verticalLayout->insertWidget(index, processViewWidget);
}

void TListProcessViewWidget::setProcessViewWidgetList(const std::vector<QWidget*>& processViewWidgetList)
{
	clearProcessViewWidget();

	for (auto processViewWidget : processViewWidgetList)
		addProcessViewWidget(processViewWidget);
}
