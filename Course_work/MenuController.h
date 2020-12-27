#pragma once
#include <fstream>
#include "WeekdaySummary.h"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/portable_binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#define N 4

class MenuController
{
public:
	int menu();

	template<class Archive>
	void serialize(Archive& archive) {
		archive(arr);
	}

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

	//int arrSize;

	vector<WeekdaySummary> arr;

};

