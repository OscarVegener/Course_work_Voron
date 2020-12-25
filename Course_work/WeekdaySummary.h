#pragma once
#include "OperationDay.h"

class WeekdaySummary
{
public:
	void addOperationDay(const OperationDay& d);

	WeekdaySummary();

	template<class Archive>
	void serialize(Archive& archive) {
		archive(arr);
	}

	const vector<OperationDay>& getOperationDayVector() const {
		return arr;
	}

private:
	vector<OperationDay> arr;
};

