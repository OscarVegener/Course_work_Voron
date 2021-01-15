#include "WeekdaySummary.h"

void WeekdaySummary::addOperationDay(const OperationDay& d) {
	if (arr.size() == 0) {
		arr.push_back(d);
		OperationDay tmp = d;
		for (int i = 1; i < 7; i++)
		{
			tmp.addDay();
			arr.push_back(tmp);
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

OperationDay& WeekdaySummary::operator[](int const& index)
{
	return arr[index];
}

const OperationDay& WeekdaySummary::operator[](int const& index) const
{
	return arr[index];
}
