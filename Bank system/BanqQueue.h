#pragma once
#include "Client.h"
#include <vector>
#include <queue>

struct com {
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
    priority_queue<Client*, vector<Client*>, com> clientsQueue;
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

    void display() {
        priority_queue<Client*, vector<Client*>, com> tempQueue = clientsQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.top()->name<<endl;
            tempQueue.pop();
        }
    }
};

