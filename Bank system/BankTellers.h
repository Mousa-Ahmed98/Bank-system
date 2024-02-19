#pragma once
#include <iostream>
#include <list>
#include "Accountant.h"
#include "Client.h"

using namespace std;
class BankTellers
{
public:

	list<Accountant*> tellersList;
	BankTellers() {
		tellersList.push_back(new Accountant(1, "Ahmed Ali", 29, Role::LoanManager));
		tellersList.push_back(new Accountant(2, "Sayed Khaled", 29, Role::LoanManager));
		tellersList.push_back(new Accountant(3, "Ahmed Wael", 29, Role::LoanManager));
		tellersList.push_back(new Accountant(4, "Nadeen mounier", 29, Role::LoanManager));
	}

	void assignAccToClient(Client* client) {
		list<Accountant*> tempTellersList = tellersList;
		Accountant* acc = tempTellersList.front();
		Accountant* targetedAcc = acc;
		while (!tempTellersList.empty()) {
			if (tempTellersList.front()->availableOn < targetedAcc->availableOn) {
				targetedAcc = tempTellersList.front();
			}
			tempTellersList.pop_front();
		}
		
		client->assignTo(targetedAcc->name);
		if (targetedAcc->availableOn < client->arrivalTime) {
			targetedAcc->availableOn = client->arrivalTime;
		}

		//Waiting Time
		client->calcWaitingTime(targetedAcc->availableOn);
		
		targetedAcc->availableOn += client->serviceTime;
		client->leavingTime = client->arrivalTime;
		targetedAcc->addServedClient();
	}


	void availability() {
		list<Accountant*> tempAccountantsList = tellersList;
		while (!tempAccountantsList.empty()) {
			cout << tempAccountantsList.front()->name << " " <<
				tempAccountantsList.front()->getNumOfServedClients()<<endl;
			tempAccountantsList.pop_front();
		}
	}




};

