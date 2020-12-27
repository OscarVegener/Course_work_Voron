#pragma once
#include <vector>
#include "Date.h"
#include "Deposit.h"

class OperationDay :
    public Date
{
public:
    OperationDay();

    OperationDay(const OperationDay& od) : Date(od){
        arr = od.getDepositVector();
    }

    OperationDay(const Date& d) : Date(d) {
    }

    void addOperation(const Deposit& op);

    template<class Archive>
    void serialize(Archive& archive) {
        archive(year, month, day, arr);
    }

    const vector<Deposit>& getDepositVector() const {
        return arr;
    }

private:
    vector<Deposit> arr;
};

