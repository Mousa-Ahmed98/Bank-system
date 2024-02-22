#pragma once
using namespace std;
#include "Person.h"
#include "MemberShip.h"
#include "Time.h"
class Client : public Person
{
	int waitingTime;
	int serviceTime;
	int arrivalTime;
	int leavingTime;
	
public:
	MemberShip memberShip;
	int priority;
	bool needSpecialNeeds;
	
	
	string assignedTo;
	Client(int id, string name, int age, MemberShip memberShip, bool needSpecialNeeds, int arrivalTime, int serviceTime) : Person(id, name, age) {
		this->memberShip = memberShip;
		this->needSpecialNeeds = needSpecialNeeds;
		this->arrivalTime = arrivalTime;
		this->serviceTime = serviceTime;
		leavingTime = 0;
		waitingTime = 0;
		priority = 10;
	}
	
	virtual string show() {
		
		return "Client";
	}

	void assignTo(string accountantName) {
		assignedTo = accountantName;
	}


	void calcWaitingTime(int telletAvailabilityTime) {
		waitingTime = telletAvailabilityTime - arrivalTime;
		leavingTime += waitingTime + serviceTime + arrivalTime;
	}

	int getWaitingTime() {
		return waitingTime;
	}

	int getArrivalTime() {
		return arrivalTime;
	}

	int getServiceTime() {
		return serviceTime;
	}

	int getLeavingTime() {
		return leavingTime;
	}

};

