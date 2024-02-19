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


int main() {
    
    
    BanqQueue* bq = new BanqQueue();
    bq->Enqueue(new Client(4, "Rawan", 21, MemberShip::GoldenAccount, true, 75, 10));
    bq->Enqueue(new Client(1, "Mousa", 25, MemberShip::GoldenAccount, false, 62, 12));
    bq->Enqueue(new Client(2, "Ahmed", 29, MemberShip::OrdinaryAccount, true, 64, 8));
    bq->Enqueue(new Client(3, "Ali", 23, MemberShip::OrdinaryAccount, false, 62, 9));
    bq->Enqueue(new Client(5, "Murad", 33, MemberShip::OrdinaryAccount, false, 62, 10));

    
    //bq->display();

    BankTellers tellers = BankTellers();

    BanqQueue tempBQ = *bq;

    while (!tempBQ.isEmpty()) {
        
        tellers.assignAccToClient(tempBQ.top());
        tempBQ.Deque();
    }
    
    bq->displayStatus();
    
    
    

    
    

    
    return 0;
}

