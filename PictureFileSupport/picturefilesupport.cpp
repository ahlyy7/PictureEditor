// PictureFileSupport.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "picturefilesupport.h"
#include <opencv2/opencv.hpp>
#include <sstream>
#include <unordered_map>
#include <regex>

std::vector<std::string> getPictureFileSupport()
{
	using std::string;
	using std::istringstream;
	using std::unordered_map;
	using std::vector;
	using std::regex;
	using std::sregex_iterator;

	static const unordered_map<string, string> table
	{
		{ "JPEG", "*.jpg *.jpeg" },
		{ "PNG", "*.png" },
		{ "WEBP", "*.webp" },
		{ "TIFF", "*.tiff *.tif" },
		{ "OpenEXR", "*.exr" },
		{ "HDR", "*.hdr" },
		{ "SUNRASTER", "*.sr *.ras" },
		{ "PXM", "*.pbm *.pgm *.ppm" }
	};

	string fileSupportList = cv::getBuildInformation();
	istringstream sin(fileSupportList);

	string mapping;

	vector<string> result;

	while (getline(sin, mapping))
	{
		regex re(R"(\S*(?=:))");
		sregex_iterator it(mapping.begin(), mapping.end(), re);
		if (it == sregex_iterator())
			continue;

		string key = it->str();



		re = R"(:\s*NO)";
		it = { mapping.begin(), mapping.end(), re };
		if (it != sregex_iterator())
			continue;

		auto map = table.find(key);
		if (map == table.end())
			continue;

		result.push_back(map->second);
	}

	return result;
}
