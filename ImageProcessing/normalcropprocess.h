#pragma once

#ifndef _NORMALCROPPROCESS_H_
#define _NORMALCROPPROCESS_H_

#include "abstractimageprocess.h"
#include <QRect>

class NormalCropProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	QRect rect;

	QRect pinch(const QRect& rect);
	QRect getImageRect();

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;
	virtual void resetArgAfterImageChanged() override;

public:
	NormalCropProcess(QObject* parent = nullptr);
	~NormalCropProcess();

	void setRect(QRect rect);
	const QRect& getRect();

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

signals:
	void rectChanged(const QRect& rect);
};

#endif // !_NORMALCROPPROCESS_H_
