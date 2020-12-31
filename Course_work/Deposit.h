#pragma once
#include "Client.h"

class Deposit
{
public:
	int getAccountNumber() const;

	void setAccountNumber(int number);

	double getSum() const;

	void setSum(double sum);

	double getPercent() const;

	void setPercent(double percent);

	const Client& getClient() const;

	void setClient(const Client& c);

	Deposit();

	Deposit(const Client& c, int accountNumber, double sum, double percent);

	Deposit(const Deposit& d);

	template<class Archive>
	void serialize(Archive& archive) {
		archive(client, accountNumber, sum, percent);
	}

private:
	Client client;
	int accountNumber;
	double sum;
	double percent;
};

inline const bool operator == (Deposit d1, Deposit d2) {
	if (d1.getAccountNumber() == d2.getAccountNumber() &&
		d1.getSum() == d2.getSum() &&
		d1.getPercent() == d2.getPercent()) {
		return true;
	}
	else {
		return false;
	}
}