#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int hh, mm;
        cin >> hh >> mm;
        cout << ((23 - hh) * 60 + (60 - mm)) << endl;
    }
    return 0;
}