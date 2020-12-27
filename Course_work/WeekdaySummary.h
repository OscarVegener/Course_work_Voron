#pragma once
#include "OperationDay.h"

using namespace std;

class WeekdaySummary
{
public:
	void addOperationDay(const OperationDay& d);

	void addDeposit(const Deposit& d, const OperationDay& od);

	int operationDayId(const OperationDay& d);

	WeekdaySummary();

	template<class Archive>
	void serialize(Archive& archive) {
		archive(arr);
	}

	const vector<OperationDay>& getOperationDayVector() const;

	double getAverageOperationsPerDay() const;

	double getAverageDepositSumPerDay() const;

private:
	vector<OperationDay> arr;
};

