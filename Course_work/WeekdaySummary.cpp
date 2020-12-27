#include "WeekdaySummary.h"

void WeekdaySummary::addOperationDay(const OperationDay& d) {
	if (arr.size() == 0) {
		arr.push_back(d);
		OperationDay tmp = d;
		for (int i = 1; i < 7; i++)
		{
			arr.push_back(++tmp);
		}
	}
	else {
		throw std::range_error("There are can't be more than 7 days in a week");
	}
}

void WeekdaySummary::addDeposit(const Deposit& d, const OperationDay& od)
{
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (*it == od) {
			it->addOperation(d);
			return;
		}
	}
	throw std::range_error("Can't add provided deposit to this week");
}

int WeekdaySummary::operationDayId(const OperationDay& d)
{
	int id = 0;
	for (auto it = arr.begin(); it != arr.end(); ++it)
	{
		if (*it == d) {
			return id;
		}
		++id;
	}
	return -1;
}

WeekdaySummary::WeekdaySummary() {}

const vector<OperationDay>& WeekdaySummary::getOperationDayVector() const {
	return arr;
}

double WeekdaySummary::getAverageOperationsPerDay() const {
	double total_op = 0;
	for (OperationDay day : arr) {
		total_op += day.getDepositVector().size();
	}
	return total_op / arr.size();
}

double WeekdaySummary::getAverageDepositSumPerDay() const {
	double total_sum = 0;
	for (OperationDay day : arr) {
		for (Deposit deposit : day.getDepositVector()) {
			total_sum += deposit.getSum();
		}
	}
	return total_sum / arr.size();
}
