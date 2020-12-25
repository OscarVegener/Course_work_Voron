#pragma once
#include "Person.h"

class Client :
    public Person
{
public:
    double getDepositIncreaseCoefficient() const;

    void setDepositIncreaseCoefficient(double coefficient);

    const Date& getFirstServiceDay() const;

    void setFirstServiceDay(int year, int month, int day);

    void setFirstServiceDay(const Date& d);

    void setClient(const string& surname,
        const string& name,
        const Date& birthday,
        const Date& firstServiceDay,
        double depositIncreaseCoefficient);

    void setClient(const string& surname,
        const string& name,
        int birthday_year,
        int birthday_month,
        int birthday_day,
        const Date& firstServiceDay,
        double depositIncreaseCoefficient);

    void setClient(const string& surname,
        const string& name,
        const Date& birthday,
        int operation_year,
        int operation_month,
        int operation_day,
        double depositIncreaseCoefficient);

    void setClient(const string& surname,
        const string& name,
        int birthday_year,
        int birthday_month,
        int birthday_day,
        int operation_year,
        int operation_month,
        int operation_day,
        double depositIncreaseCoefficient);

    void setClient(const Person& p, const Date& firstServiceDay, double depositIncreaseCoefficient);

    void setClient(const Person& p, int operation_year, int operation_month, int operation_day, double depositIncreaseCoefficient);

    Client();

    Client(const string& surname,
        const string& name,
        const Date& birthday,
        const Date& firstServiceDay,
        double depositIncreaseCoefficient);

    Client(const string& surname,
        const string& name,
        int birthday_year,
        int birthday_month,
        int birthday_day,
        const Date& firstServiceDay,
        double depositIncreaseCoefficient);

    Client(const string& surname,
        const string& name,
        const Date& birthday,
        int operation_year,
        int operation_month,
        int operation_day,
        double depositIncreaseCoefficient);

    Client(const string& surname,
        const string& name,
        int birthday_year,
        int birthday_month,
        int birthday_day,
        int operation_year,
        int operation_month,
        int operation_day,
        double depositIncreaseCoefficient);

    Client(const Person& p,
        const Date& firstServiceDay,
        double depositIncreaseCoefficient);

    Client(const Client& c);

    template<class Archive>
    void serialize(Archive& archive) {
        archive(surname, name, birthday, firstServiceDay, depositIncreaseCoefficient);
    }

private:
    Date firstServiceDay;
    double depositIncreaseCoefficient;
};

