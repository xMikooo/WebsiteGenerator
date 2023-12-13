#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class PropertiesGenerator
{
private:
	std::ofstream outProperties;

public:
	PropertiesGenerator();
	~PropertiesGenerator();
};


