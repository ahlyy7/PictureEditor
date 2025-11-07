#pragma once

#ifndef _HORIZONTALLINE_H_
#define _HORIZONTALLINE_H_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HorizontalLineClass; };
QT_END_NAMESPACE

class HorizontalLine : public QWidget
{
	Q_OBJECT

public:
	HorizontalLine(QWidget* parent = nullptr);
	~HorizontalLine();

private:
	Ui::HorizontalLineClass* ui;
};

#endif // !_HORIZONTALLINE_H_
