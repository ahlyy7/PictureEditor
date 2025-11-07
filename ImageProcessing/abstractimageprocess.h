#pragma once

#ifndef _ABSTRACTIMAGEPROCESS_H_
#define _ABSTRACTIMAGEPROCESS_H_

#include <qobject.h>

namespace cv
{
	class Mat;
};

class AbstractImageProcess : public QObject
{
	Q_OBJECT

private:
	bool canProcess;
	bool canReset;
	cv::Mat* target;

protected:
	void reJudge();

	//	保证在image不为空时，调用
	virtual void process() = 0;
	//	保证在image不为空时，调用
	virtual void resetArgAfterImageChanged();

public:
	//	保证在image不为空时，调用
	virtual bool processable() = 0;
	virtual bool resetable() = 0;
	virtual QString processName() = 0;

	virtual void resetArg() = 0;

	cv::Mat* getImage();
	void setImage(cv::Mat* target);

	bool tryProcess();

	AbstractImageProcess(QObject* parent = nullptr, cv::Mat* target = nullptr);
	virtual ~AbstractImageProcess() = 0;

signals:
	void reJudged();

	void processableChanged(bool process);
	void resetableChanged(bool reset);
	void processed();

	void imageChanged(cv::Mat* image);
};

#endif // !_ABSTRACTIMAGEPROCESS_H_
