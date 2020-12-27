#pragma once
#include <fstream>
#include <iomanip>
#include "WeekdaySummary.h"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/portable_binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"

class MenuController
{
public:
	int menu();

private:

	void loadFile();

	void saveFile();

	void loadFromBinaryFile(const string& filePath);

	void loadFromJSONFile(const string& filePath);

	void saveToBinaryFile(const string& filePath);

	void saveToJSONFile(const string& filePath);

	void enterNewData();

	void addNewDeposit(const Deposit& d, const Date& dt);

	void printData();

	void findClient();

	void findDeposit();

	vector<WeekdaySummary> arr;

};

