#pragma once
#include <stdexcept>
#include <string>
#include "Date.h"

using namespace std;

class Person
{
public:
	const string& getSurname() const;

	void setSurname(const string& surname);

	const string& getName() const;

	void setName(const string& name);

	const Date& getBirthday() const;

	void setBirthday(int year, int month, int day);

	void setBirthday(const Date& d);

	void setPerson(const string& surname, const string& name, const Date& birthday);

	void setPerson(const string& surname, const string& name, int year, int month, int day);

	Person();

	Person(const string& surname, const string& name, const Date& birthday);

	Person(const string& surname, const string& name, int year, int month, int day);

	Person(const Person& p);

	virtual ~Person();

protected:
	string surname;
	string name;
	Date birthday;
};

