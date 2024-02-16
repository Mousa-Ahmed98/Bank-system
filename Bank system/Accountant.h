#pragma once
using namespace std;
#include "Person.h"
#include "Role.h"
class Accountant : public Person
{
	Role role;
	

public:
	bool isAvailable;
	Accountant(int id, string name, int age, Role role) : Person(id, name, age) {
		this->role = role;
		isAvailable = true;
	}
	
	virtual string show() {
		return "Accountant";
	}



};

