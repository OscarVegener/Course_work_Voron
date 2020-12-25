#include "Client.h"

double Client::getDepositIncreaseCoefficient() const {
    return depositIncreaseCoefficient;
}

void Client::setDepositIncreaseCoefficient(double coefficient) {
    coefficient >= 0 ? depositIncreaseCoefficient = coefficient :
        throw std::range_error("DepositIncreaseCoefficient can't be lesser than 0");
}

const Date& Client::getFirstServiceDay() const {
    return firstServiceDay;
}

void Client::setFirstServiceDay(int year, int month, int day) {
    firstServiceDay.setDate(year, month, day);
}

void Client::setFirstServiceDay(const Date& d) {
    firstServiceDay.setDate(d);
}

void Client::setClient(const string& surname,
    const string& name, const Date& birthday,
    const Date& firstServiceDay,
    double depositIncreaseCoefficient)
{
    setPerson(surname, name, birthday);
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

void Client::setClient(const string& surname,
    const string& name,
    int birthday_year,
    int birthday_month,
    int birthday_day,
    const Date& firstServiceDay,
    double depositIncreaseCoefficient)
{
    setPerson(surname, name, birthday_year, birthday_month, birthday_day);
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

void Client::setClient(const string& surname,
    const string& name, const Date& birthday,
    int operation_year,
    int operation_month,
    int operation_day,
    double depositIncreaseCoefficient)
{
    setPerson(surname, name, birthday);
    setFirstServiceDay(operation_year, operation_month, operation_day);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

void Client::setClient(const string& surname,
    const string& name,
    int birthday_year,
    int birthday_month,
    int birthday_day,
    int operation_year,
    int operation_month,
    int operation_day,
    double depositIncreaseCoefficient)
{
    setPerson(surname, name, birthday_year, birthday_month, birthday_day);
    setFirstServiceDay(operation_year, operation_month, operation_day);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

void Client::setClient(const Person& p, const Date& firstServiceDay, double depositIncreaseCoefficient) {
    setPerson(p.getSurname(), p.getName(), p.getBirthday());
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

void Client::setClient(const Person& p,
    int operation_year,
    int operation_month,
    int operation_day,
    double depositIncreaseCoefficient) {
    setPerson(p.getSurname(), p.getName(), p.getBirthday());
    setFirstServiceDay(operation_year, operation_month, operation_day);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

Client::Client() : Person() {}

Client::Client(const string& surname,
    const string& name,
    const Date& birthday,
    const Date& firstServiceDay,
    double depositIncreaseCoefficient) :
    Person(surname, name, birthday)
{
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}



Client::Client(const string& surname,
    const string& name,
    int birthday_year,
    int birthday_month,
    int birthday_day,
    const Date& firstServiceDay,
    double depositIncreaseCoefficient) :
    Person(surname, name, birthday_year, birthday_month, birthday_day)
{
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

Client::Client(const string& surname,
    const string& name,
    const Date& birthday,
    int operation_year,
    int operation_month,
    int operation_day,
    double depositIncreaseCoefficient) :
    Person(surname, name, birthday)
{
    setFirstServiceDay(operation_year, operation_month, operation_day);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

Client::Client(const string& surname,
    const string& name,
    int birthday_year,
    int birthday_month,
    int birthday_day,
    int operation_year,
    int operation_month,
    int operation_day,
    double depositIncreaseCoefficient) :
    Person(surname, name, birthday_year, birthday_month, birthday_day)
{
    setFirstServiceDay(operation_year, operation_month, operation_day);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

Client::Client(const Person& p, const Date& firstServiceDay, double depositIncreaseCoefficient) :
    Person(p.getSurname(), p.getName(), p.getBirthday())
{
    setFirstServiceDay(firstServiceDay);
    setDepositIncreaseCoefficient(depositIncreaseCoefficient);
}

Client::Client(const Client& c) : Person(c) {
    setFirstServiceDay(c.getFirstServiceDay().getYear(),
        c.getFirstServiceDay().getMonth(),
        c.getFirstServiceDay().getDay());
    setDepositIncreaseCoefficient(c.getDepositIncreaseCoefficient());
}
