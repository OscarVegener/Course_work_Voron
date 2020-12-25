#pragma once
#include <stdexcept>

class Date
{
public:
	int getYear() const;

	void setYear(int year);

	int getMonth() const;

	void setMonth(int month);

	int getDay() const;

	void setDay(int day);

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

protected:
	int year = 1;
	int month = 1;
	int day = 1;
};

