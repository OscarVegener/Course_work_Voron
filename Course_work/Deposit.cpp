#include "Deposit.h"

int Deposit::getAccountNumber() const {
	return accountNumber;
}

void Deposit::setAccountNumber(int number) {
	number > 0 ? accountNumber = number : throw std::range_error("Account number can't be less than 0");
}

double Deposit::getSum() const {
	return sum;
}

void Deposit::setSum(double sum) {
	this->sum = sum;
}

double Deposit::getPercent() const {
	return percent;
}

void Deposit::setPercent(double percent) {
	percent >= 0 && percent <= 100 ? this->percent = percent :
		throw std::range_error("Deposit percent can't be less than 0 or greater than 100");
}

const Client& Deposit::getClient() const {
	return client;
}

void Deposit::setClient(const Client& c) {
	client.setClient(c.getSurname(), c.getName(), c.getBirthday(), c.getFirstServiceDay(), c.getDepositIncreaseCoefficient());
}

Deposit::Deposit() {}

Deposit::Deposit(const Client& c, int accountNumber, double sum, double percent) {
	setClient(c);
	setAccountNumber(accountNumber);
	setSum(sum);
	setPercent(percent);
}

Deposit::Deposit(const Deposit& d) {
	setClient(d.getClient());
	setAccountNumber(d.getAccountNumber());
	setSum(d.getSum());
	setPercent(d.getPercent());
}
