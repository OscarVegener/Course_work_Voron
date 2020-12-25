#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Client.h"
#include "Deposit.h"
#include "OperationDay.h"
#include "WeekdaySummary.h"

#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/cereal.hpp"
#include "cereal/types/vector.hpp"
//#include "cereal/types/string.hpp"
#include <fstream>

using namespace std;


int main()
{
	try {
		Date d(2001, 10, 3);
		Person p;
		p.setSurname("Surname");
		p.setName("Name");
		p.setBirthday(d);
		p.setBirthday(2020, 1, 3);
		cout << p.getName() 
			<< " " << p.getSurname() 
			<< " " << p.getBirthday().getYear() 
			<< "." << p.getBirthday().getMonth()
			<< "." << p.getBirthday().getDay() 
			<< endl;
		Client c(p, d, 0.03);
		cout << c.getName()
			<< " " << c.getSurname()
			<< " " << c.getBirthday().getYear()
			<< "." << c.getBirthday().getMonth()
			<< "." << c.getBirthday().getDay()
			<< "." << c.getFirstServiceDay().getYear()
			<< "." << c.getFirstServiceDay().getMonth()
			<< "." << c.getFirstServiceDay().getDay()
			<< "." << c.getDepositIncreaseCoefficient()
			<< endl;
		Deposit dp(c, 178231289, 300.00, 3.21);
		OperationDay od;
		od.addOperation(dp);
		WeekdaySummary w;
		w.addOperationDay(od);
		ofstream ss;
		ss.open("file", ios::trunc);
		{
			//cereal::BinaryOutputArchive oarchive(ss);
			//oarchive(w);
			cereal::JSONOutputArchive oarchive(ss);
			oarchive(w);
		}
		system("pause");
		ifstream ff;
		ff.open("file", ios::in);
		{
			cereal::JSONInputArchive iarchive(ff);
			iarchive(w);
		}
		cout << w.getOperationDayVector()[0].getDepositVector()[0].getAccountNumber() << endl;
	}	
	catch (std::exception e){
		cout << e.what() << endl;
	}
	return 0;
}