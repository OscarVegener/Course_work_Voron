#include "Person.h"

const string& Person::getSurname() const {
	return surname;
}

void Person::setSurname(const string& surname) {
	this->surname = surname;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}

const Date& Person::getBirthday() const {
	return birthday;
}

void Person::setBirthday(int year, int month, int day) {
	birthday.setDate(year, month, day);
}

void Person::setBirthday(const Date& d) {
	birthday.setDate(d);
}

void Person::setPerson(const string& surname, const string& name, const Date& birthday)
{
	setSurname(surname);
	setName(name);
	setBirthday(birthday);
}

void Person::setPerson(const string& surname, const string& name, int year, int month, int day)
{
	setSurname(surname);
	setName(name);
	setBirthday(year, month, day);
}

Person::Person()
{
}

Person::Person(const string& surname, const string& name, const Date& birthday)
{
	setPerson(surname, name, birthday);
}

Person::Person(const string& surname, const string& name, int year, int month, int day)
{
	setPerson(surname, name, year, month, day);
}

Person::Person(const Person& p)
{
	surname = p.getSurname();
	name = p.getName();
	birthday = p.getBirthday();
}

Person::~Person()
{

}
