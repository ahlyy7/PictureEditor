#pragma once

#ifndef _GRAFFITIPROCESS_H_
#define _GRAFFITIPROCESS_H_

#include "abstractimageprocess.h"

class TGraphicsStackFilterWindow;

class GraffitiProcess : public AbstractImageProcess
{
	Q_OBJECT

private:
	TGraphicsStackFilterWindow* graphicsStackFilterWindow;

protected:
	// 通过 AbstractImageProcess 继承
	void process() override;

public:
	GraffitiProcess(QObject* parent = nullptr);
	~GraffitiProcess();

	void setGraphicsStackFilterWindow(TGraphicsStackFilterWindow* graphicsStackFilterWindow);
	TGraphicsStackFilterWindow* getGraphicsStackFilterWindow() const;

	bool processable() override;
	bool resetable() override;
	QString processName() override;
	void resetArg() override;

signals:
	void graphicsStackFilterWindowChanged(TGraphicsStackFilterWindow* graphicsStackFilterWindow);
};

#endif // !_GRAFFITIPROCESS_H_
