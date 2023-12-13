#include "FileOut.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream outCss;
ofstream outHtml;


FileOut::FileOut(){

	outCss.open("style.css", ios_base::trunc);
	outHtml.open("index.html", ios_base::trunc);
	if (!outCss || !outHtml) {
		throw runtime_error("Błąd otwierania pliku");
		delete this;
	}
}



FileOut::~FileOut()
{
	outCss.close();
	outHtml.close();
}

void FileOut::writeCssOption(string obj, vector<pair<string, string>> options)
{
	outCss << obj << " {" << endl;
	for (auto option : options) {
		outCss << "\t" << option.first << ": " << option.second << ";" << endl;
	}
	outCss << "}" << endl;
}

void FileOut::writeHtmlOption(string tag, vector<pair<string, string>> options, bool closeTag, string content, int tabs)
{

	string tabString = "";
	if (tabs) for (int i = 0; i < tabs; i++) {
		tabString += "\t";
	}

	outHtml << tabString << "<" << tag;
	for (auto option : options) {
		outHtml << " " << option.first << "=\"" << option.second << "\"";
	}
	outHtml << ">";
	outHtml << content;
	if (closeTag) {
		outHtml << "</" << tag << ">";
	}
	outHtml << endl;
}

void FileOut::writeClosingTag(string tag, int tabs) {
	string tabString = "";
	if (tabs) for (int i = 0; i < tabs; i++) {
		tabString += "\t";
	}
	outHtml << tabString << "</" << tag << ">" << endl;
}