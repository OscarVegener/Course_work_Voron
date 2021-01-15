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

	void meanSum();

	void meanOperations();

	void find();

	vector<WeekdaySummary> arr;

	template<class T>
	double getStatistics(const vector<T>& arr) const;

};

template<class T>
inline double MenuController::getStatistics(const vector<T>& arr) const
{
	if (arr.size() == 0) {
		return 0.0;
	}
	double total = 0;
	for (T item : arr) {
		total += item.getStatisticalData();
	}
	return total / arr.size();
}
