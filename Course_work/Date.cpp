#include "Date.h"

int Date::getYear() const {
	return year;
}

void Date::addDay()
{
	int day = this->getDay() + 1;
	int year = this->getYear();
	int month = this->getMonth();
	if (day > 31) {
		month++;
		day = 1;
		if (month > 12) {
			year++;
			month = 1;
			this->setDate(year, month, day);
			return;
		}
		this->setDate(year, month, day);
		return;
	}
	this->setDate(year, month, day);
	return;
}

void Date::setYear(int year) {
	year > 1920 && year < 2022 ? this->year = year : throw std::range_error("The year can't be lesser than 0");
}

int Date::getMonth() const {
	return month;
}

void Date::setMonth(int month) {
	month > 0 && month < 13 ? this->month = month : throw std::range_error("The month can't be lesser than 0 or greater than 12");
}

int Date::getDay() const {
	return day;
}

void Date::setDay(int day) {
	day > 0 && day <= 31 ? this->day = day : throw std::range_error("The day can't be lesser than 0 or greater than 31");
}

Date::Date()
{
	
}

Date::Date(int year, int month, int day)
{
	setDate(year, month, day);
}

Date::Date(const Date& d)
{
	setYear(d.getYear());
	setMonth(d.getMonth());
	setDay(d.getDay());
}

Date::~Date()
{

}

void Date::setDate(int year, int month, int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

void Date::setDate(const Date& d)
{
	setYear(d.getYear());
	setMonth(d.getMonth());
	setDay(d.getDay());
}
