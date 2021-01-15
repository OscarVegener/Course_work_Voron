#include "OperationDay.h"

OperationDay::OperationDay() : Date() {}

void OperationDay::addOperation(const Deposit& op) {
    arr.push_back(op);
}

Deposit& OperationDay::operator[](int const& index)
{
    return arr[index];
}

const Deposit& OperationDay::operator[](int const& index) const
{
    return arr[index];
}

int OperationDay::getStatisticalData() const
{
    // total deposit operations
    return arr.size();
}

