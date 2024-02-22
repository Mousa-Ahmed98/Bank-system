#include <iostream>
#include<Queue>
#include<vector>
#include "Person.h"
#include "Client.h"
#include <iostream>
#include <queue>
#include <vector>
#include "MemberShip.h" // Assuming this header file defines the Client class
#include "BanqQueue.h"
#include "Time.h"
#include "BankTellers.h"

using namespace std;

int BanqQueue::startingPriority = 0;
int BankTellers::countOfClientsServed = 0;


int main() {
    
    
    BanqQueue* bq = new BanqQueue();
    /*bq->Enqueue(new Client(4, "Rawan", 21, MemberShip::GoldenAccount, true, 75, 10));
    bq->Enqueue(new Client(1, "Mousa", 25, MemberShip::GoldenAccount, false, 62, 12));
    bq->Enqueue(new Client(2, "Ahmed", 29, MemberShip::OrdinaryAccount, true, 64, 8));
    bq->Enqueue(new Client(3, "Ali", 23, MemberShip::OrdinaryAccount, false, 68, 9));
    bq->Enqueue(new Client(5, "Murad", 33, MemberShip::OrdinaryAccount, false, 62, 10));*/
    bq->Enqueue(new Client(1, "Murad", 33, MemberShip::OrdinaryAccount, false, 0, 3));
    bq->Enqueue(new Client(10, "Soliman", 33, MemberShip::OrdinaryAccount, false, 12, 5));
    bq->Enqueue(new Client(3, "Bassam", 33, MemberShip::OrdinaryAccount, false, 2, 2));
    bq->Enqueue(new Client(8, "Mousa", 33, MemberShip::OrdinaryAccount, false, 10, 3));
    bq->Enqueue(new Client(4, "Sayed", 33, MemberShip::OrdinaryAccount, false, 4, 5));
    bq->Enqueue(new Client(5, "Shaaban", 33, MemberShip::OrdinaryAccount, false, 5, 4));
    bq->Enqueue(new Client(2, "Samir", 33, MemberShip::OrdinaryAccount, false, 1, 7));
    bq->Enqueue(new Client(6, "Ragab", 33, MemberShip::OrdinaryAccount, false, 7, 4));
    bq->Enqueue(new Client(7, "Abdo", 33, MemberShip::OrdinaryAccount, false, 8, 6));
    bq->Enqueue(new Client(9, "Nader", 33, MemberShip::OrdinaryAccount, false, 11, 2));



    
    //bq->display();

    BankTellers tellers = BankTellers();

    BanqQueue tempBQ = *bq;

    while (!tempBQ.isEmpty()) {
        
        tellers.assignAccToClient(tempBQ.top());
        tempBQ.Deque();
    }
    
    cout << "Customer name       " << "Arrival time   " << "Service time   " << "Waiting time   "
        << "Leaving time   " << "Teller name"<<endl;
    bq->displayStatus();
    
    
    
    tellers.getStatistics(bq->getAverageWitingTime(), bq->getAverageServiceTime());
    //tellers.availability();
    

    
    return 0;
}

