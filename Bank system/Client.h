#pragma once
using namespace std;
#include "Person.h"
#include "MemberShip.h"
#include "Time.h"
class Client : public Person
{
	
	
public:
	MemberShip memberShip;
	int priority;
	bool needSpecialNeeds;
	int serviceTime;
	int arrivalTime;
	int leavingTime;
	Client(int id, string name, int age, MemberShip memberShip, bool needSpecialNeeds, int arrivalTime, int serviceTime) : Person(id, name, age) {
		this->memberShip = memberShip;
		this->needSpecialNeeds = needSpecialNeeds;
		this->arrivalTime = arrivalTime;
		this->serviceTime = serviceTime;
		priority = 10;
	}
	
	virtual string show() {
		
		return "Client";
	}

};

