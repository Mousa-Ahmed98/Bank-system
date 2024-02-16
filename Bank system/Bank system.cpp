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

using namespace std;

int BanqQueue::startingPriority = 0;


int main() {
    
    //Client* c1 = new Client(1, "Mousa", 25, MemberShip::GoldenAccount, false);
    BanqQueue bq = BanqQueue();
    bq.Enqueue(new Client(4, "Rawan", 21, MemberShip::GoldenAccount, true, 62, 10));
    bq.Enqueue(new Client(1, "Mousa", 25, MemberShip::GoldenAccount, false, 64, 12));
    bq.Enqueue(new Client(2, "Ahmed", 29, MemberShip::OrdinaryAccount, true, 53, 8));
    bq.Enqueue(new Client(3, "Ali", 23, MemberShip::OrdinaryAccount, false, 23, 5));
    bq.Enqueue(new Client(5, "Murad", 33, MemberShip::OrdinaryAccount, false, 89, 10));


    bq.display();
    
    return 0;
}

