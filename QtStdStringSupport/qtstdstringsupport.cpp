// QtStdStringSupport.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "qtstdstringsupport.h"

std::string toStdString(const QString& str)
{
	auto byteArray = str.toLocal8Bit();
	std::string result = byteArray.constData();

	return result;
}

QString toQtString(const std::string& str)
{
	QString result = QString::fromLocal8Bit(str);

	return result;
}
