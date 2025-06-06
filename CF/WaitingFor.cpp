#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int events;
    cin >> events;
    int totalPeople = 0;
    while(events-- > 0) {
        char ch;
        cin >> ch;
        if(ch == 'P') {
            int arrivedPeople;
            cin >> arrivedPeople;
            totalPeople += arrivedPeople; 
        } else if(ch == 'B') {
            int noOfFreeSeats;
            cin >> noOfFreeSeats;
            if((noOfFreeSeats - totalPeople) >= 1) {
                totalPeople = 0;
                cout << "YES" << endl;
            } else {
                totalPeople -= noOfFreeSeats;
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}