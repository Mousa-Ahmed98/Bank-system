#pragma once
#include <iostream>
#include <list>
#include "Accountant.h"
#include "Client.h"
#include <string>

using namespace std;
class BankTellers
{
	void printAwesome(string s) {
		for (int i = 0; i < s.length(); i++) {
			cout << s[i];
			int j = 0;
			while (j < 8000000) {
				j++;
			}
		}


		for (int i = 0; i < s.length(); i++) {
			int j = 0;
			while (j < 5000000) {
				j++;
			 }
		}
 }
public:
	static int countOfClientsServed;
	list<Accountant*> tellersList;
	BankTellers() {
		tellersList.push_back(new Accountant(1, "Ahmed Ali", 29, Role::LoanManager));
		tellersList.push_back(new Accountant(2, "Sayed Khaled", 29, Role::LoanManager));
		tellersList.push_back(new Accountant(3, "Ahmed Wael", 29, Role::LoanManager));
		//tellersList.push_back(new Accountant(4, "Nadeen mounier", 29, Role::LoanManager));
	}

	void assignAccToClient(Client* client) {
		list<Accountant*> tempTellersList = tellersList;
		
		Accountant* targetedAcc = tempTellersList.front();
		while (!tempTellersList.empty()) {
			if (tempTellersList.front()->availableOn < targetedAcc->availableOn
				|| (tempTellersList.front()->availableOn == targetedAcc->availableOn
					&& tempTellersList.front()->getNumOfServedClients() < targetedAcc->getNumOfServedClients()))
			{
				targetedAcc = tempTellersList.front();
			}
			tempTellersList.pop_front();
		}
		
		client->assignTo(targetedAcc->name);
		if (targetedAcc->availableOn < client->getArrivalTime()) {
			targetedAcc->availableOn = client->getArrivalTime();
		}

		//Waiting Time
		client->calcWaitingTime(targetedAcc->availableOn);
		countOfClientsServed++;
		
		targetedAcc->availableOn += client->getServiceTime();
		
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

	void getStatistics(double averageWaitingTime, double averageServiceTime) {
		
		//cout << "Count of tellers is                                       " << tellersList.size() << endl;
		//cout << "Average waiting time                                      " << averageWaitingTime << endl;
		//cout << "Average Service time                                      " << averageServiceTime << endl;
		printAwesome("Count of tellers is                                       " + to_string(tellersList.size()) + "\n");
		printAwesome("Average waiting time                                      " + to_string(averageWaitingTime) + "\n");
		printAwesome("Average serving time                                      " + to_string(averageServiceTime) + "\n");
		list<Accountant*> tempTellerList = tellersList;
		while (!tempTellerList.empty()) {
			printAwesome(tempTellerList.front()->name + " served " 
				+ to_string(tempTellerList.front()->getNumOfServedClients()) + " With serving rate           ");
			for (int i = 0; i < (20 - tempTellerList.front()->name.length()); i++)
				cout << " ";
			printAwesome(to_string(tempTellerList.front()->getNumOfServedClients() * 1.0 / countOfClientsServed) + "\n");


			/*cout << tempTellerList.front()->name
				<< " Served " << tempTellerList.front()->getNumOfServedClients() <<
				" With serving rate           ";
			for (int i = 0; i < (20 - tempTellerList.front()->name.length()); i++)
				cout << " ";
				cout<<tempTellerList.front()->getNumOfServedClients() * 1.0 / countOfClientsServed
				<< endl;*/
			tempTellerList.pop_front();
		}
		
	}




};

