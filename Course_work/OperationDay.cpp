#include "OperationDay.h"

OperationDay::OperationDay() : Date() {}

void OperationDay::addOperation(const Deposit& op) {
    arr.push_back(op);
}
