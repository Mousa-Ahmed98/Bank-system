#pragma once
using namespace std;
#include "Person.h"
#include "Role.h"
class Accountant : public Person
{
private:
	Role role;
	int numOfServedClients;

public:
	int availableOn;
	Accountant(int id, string name, int age, Role role) : Person(id, name, age) {
		this->role = role;
		availableOn = 0;
		numOfServedClients = 0;
	}
	
	virtual string show() {
		return "Accountant";
	}

	void addServedClient() {
		numOfServedClients++;
	}

	int getNumOfServedClients() {
		return numOfServedClients;
	}



};

