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
                return c1->priority > c2->priority;

        }

    }
};

class BanqQueue
{
    
    static int startingPriority;
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
    

    

    void displayStatus() {
        priority_queue<Client*, vector<Client*>, comb> tempQueue = clientsQueue;
        while (!tempQueue.empty()) {
            cout << "------------------------------------------------------------------------"<<endl;
            
            printAwesome(tempQueue.top()->name, 1);
            cout << "    ";

            printAwesome(to_string(tempQueue.top()->arrivalTime), 0);
            cout << "    ";

            printAwesome(to_string(tempQueue.top()->serviceTime), 0);
            cout << "    ";

            printAwesome(to_string(tempQueue.top()->getWaitingTime()), 0);
            cout << "    ";

            printAwesome(tempQueue.top()->assignedTo, 0);
            
            cout << endl << "------------------------------------------------------------------------" << endl;

            cout << endl << endl;
            tempQueue.pop();
        }
    }

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
            int t = 5 - s.length();
            for (int i = 0; i < t; i++) {
                cout << " ";
                int j = 0;
                while (j < 1000000) {
                    j++;
                }
            }
        }
    }
};

