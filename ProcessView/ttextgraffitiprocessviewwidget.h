#pragma once

#ifndef _TTEXTGRAFFITIPROCESSVIEWWIDGET_H_
#define _TTEXTGRAFFITIPROCESSVIEWWIDGET_H_

#include "tprocessviewwidgetabstract.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TTextGraffitiProcessViewWidgetClass; };
QT_END_NAMESPACE

class QTextOption;

class TTextGraffitiProcessViewWidget : public TProcessViewWidgetAbstract
{
	Q_OBJECT

private:
	std::unique_ptr<QTextOption> textOption;

public:
	TTextGraffitiProcessViewWidget(QWidget* parent = nullptr);
	~TTextGraffitiProcessViewWidget();

	void setTextOption(const QTextOption& textOption);

signals:
	void textChanged(QString text);
	void textOptionChanged(const QTextOption& textOption);

private:
	Ui::TTextGraffitiProcessViewWidgetClass* ui;
};

#endif // !_TTEXTGRAFFITIPROCESSVIEWWIDGET_H_
