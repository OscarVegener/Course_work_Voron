#pragma once
#include <stdexcept>

class Date
{
public:
	int getYear() const;

	int getMonth() const;

	int getDay() const;

	void setDate(int year, int month, int day);

	void setDate(const Date& d);

	Date();

	Date(int year, int month, int day);

	Date(const Date& d);

	virtual ~Date();

	template<class Archive>
	void serialize(Archive& archive) {
		archive(year, month, day);
	}

	void addDay();

private:
	void setYear(int year);

	void setMonth(int month);

	void setDay(int day);

protected:
	int year = 1;
	int month = 1;
	int day = 1;
};

inline const int operator - (Date d1, Date d2) {
	return d1.getYear() * 365 + int(d1.getMonth() * 30.417) + d1.getDay() - d2.getYear() * 366 - int(d2.getMonth() * 30.417) - d2.getDay();
}

inline const bool operator == (Date d1, Date d2) {
	if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay()) {
		return true;
	}
	else {
		return false;
	}
}

