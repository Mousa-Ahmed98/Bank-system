#pragma once
#include "Client.h"
#include <vector>
#include <queue>
#include<string>
using namespace std;

struct comb {
    bool operator()(Client* c1, Client* c2) {
        
        if (c1->needSpecialNeeds && !c2->needSpecialNeeds)
            return false;
        else if (c2->needSpecialNeeds && !c1->needSpecialNeeds)
            return true;
        else
        {
            if (c1->memberShip == MemberShip::GoldenAccount && c2->memberShip != MemberShip::GoldenAccount)
                return false;
            else if (c1->memberShip != MemberShip::GoldenAccount && c2->memberShip == MemberShip::GoldenAccount)
                return true;
            else
                return c1->getArrivalTime() > c2-> getArrivalTime();

        }

    }
};

class BanqQueue
{
    
    static int startingPriority;
    void printAwesome(string s, bool nameFlag) {
        for (int i = 0; i < s.length(); i++) {
            cout << s[i];
            int j = 0;
            while (j < 8000000) {
                j++;
            }
        }

        if (nameFlag) {
            int t = 25 - s.length();
            for (int i = 0; i < t; i++) {
                cout << " ";
                int j = 0;
                while (j < 1000000) {
                    j++;
                }
            }
        }
        else

        {
            int t = 8 - s.length();
            for (int i = 0; i < t; i++) {
                cout << " ";
                int j = 0;
                while (j < 1000000) {
                    j++;
                }
            }
        }

        for (int i = 0; i < s.length(); i++) {

            int j = 0;
            while (j < 20000000) {
                j++;
            }
        }
    }
public:
    priority_queue<Client*, vector<Client*>, comb> clientsQueue;
    BanqQueue() {
        
    }

    void Enqueue(Client* c) {
        c->priority = startingPriority++;
        clientsQueue.push(c);
    }

    void Deque() {
        if (clientsQueue.size() > 0) {
            clientsQueue.pop();
        }
    }

    bool isEmpty() {
        return clientsQueue.empty();
    }

    Client* top() {
        return clientsQueue.top();
    }

    double getAverageWitingTime() {
        double totalWaitingTime = 0.0;

        priority_queue<Client*, vector<Client*>, comb> tempQueue = clientsQueue;
        while (!tempQueue.empty()) {
            totalWaitingTime += tempQueue.top()->getWaitingTime();
            tempQueue.pop();
        }
        

        return totalWaitingTime / clientsQueue.size();
    }

    double getAverageServiceTime() {
        
        double totalServiceTime = 0.0;
        priority_queue<Client*, vector<Client*>, comb> tempQueue = clientsQueue;
        while (!tempQueue.empty()) {
            totalServiceTime += tempQueue.top()->getServiceTime();
            tempQueue.pop();
        }
        
        return totalServiceTime / clientsQueue.size();
    }
    

    

    void displayStatus() {
        priority_queue<Client*, vector<Client*>, comb> tempQueue = clientsQueue;
        while (!tempQueue.empty()) {
            //cout << "------------------------------------------------------------------------------------------------------"<<endl;
            cout << endl;
            printAwesome(tempQueue.top()->name, 1);
            cout << " ";

            printAwesome(to_string(tempQueue.top()->getArrivalTime()), 0);
            cout << "      ";

            printAwesome(to_string(tempQueue.top()->getServiceTime()), 0);
            cout << "       ";

            printAwesome(to_string(tempQueue.top()->getWaitingTime()), 0);
            cout << "      ";

            printAwesome(to_string(tempQueue.top()->getLeavingTime()), 0);
            cout << "    ";

            printAwesome(tempQueue.top()->assignedTo, 0);
            
            //cout << endl << "------------------------------------------------------------------------------------------------------" << endl;

            cout << endl << endl;
            tempQueue.pop();
        }
    }

    
};

