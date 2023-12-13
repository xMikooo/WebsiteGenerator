#pragma once
#include <string>
#include <vector>
#include <istream>

class CustomizationOptions {
public:
	std::string bgColor;
	std::string bgPath;
	bool bgPictureEnabled;
	bool bgVerticalRepeat;
	bool bgHorizontalRepeat;
	bool bgStretch;
	bool bgFixed;
	std::string siteName;
	int nameSize;
	std::string nameColor;
	int colNum;
	std::vector<std::string> colContent;
	std::vector<int> colFontSize;
	std::vector<std::string> colFontColor;
	std::vector<std::string> colBgColor;
	std::vector<std::string> colBgPath;
	std::vector<bool> colBgPictureEnabled;
	std::vector<bool> colVerticalRepeat;
	std::vector<bool> colHorizontalRepeat;
	std::vector<bool> colStretch;
	std::vector<bool> colFixed;
	std::vector<int> colRoundedCornersRadius;
	std::string footerBgColor;
	std::string footerBgPath;
	bool footerBgPictureEnabled;
	bool footerBgVerticalRepeat;
	bool footerBgHorizontalRepeat;
	bool footerBgStretch;
	bool footerBgFixed;
	std::string footerFontColor;
	int footerFontSize;
	std::string footerText;
	
	CustomizationOptions();
	CustomizationOptions(std::istream&);

};
