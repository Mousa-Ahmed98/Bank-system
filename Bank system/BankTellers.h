#pragma once
#include <iostream>
#include <list>
#include "Accountant.h"

using namespace std;
class BankTellers
{
	list<Accountant*> accountantsList;
	BankTellers() {
		accountantsList.push_back(new Accountant(1, "Ahmed Ali", 29, Role::LoanManager));
		accountantsList.push_back(new Accountant(2, "Sayed Khaled", 29, Role::LoanManager));
		accountantsList.push_back(new Accountant(3, "Ahmed Wael", 29, Role::LoanManager));
		accountantsList.push_back(new Accountant(4, "Nadeen mounier", 29, Role::LoanManager));
	}


};

