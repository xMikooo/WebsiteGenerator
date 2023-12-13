#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileOut
{
private:
	std::ofstream outCss;
	std::ofstream outHtml;

public:
	FileOut();
	~FileOut();
	void writeCssOption(std::string obj, vector<pair<string, string>> options);
	void writeHtmlOption(std::string tag, vector<pair<string, string>> options, bool closeTag = true, string content="", int tabs=0);
	void writeClosingTag(string tag, int tabs = 0);
};

