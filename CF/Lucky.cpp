#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 10 + (n / 10) % 10 + (n/100)%10 == (n/1000)%10 + (n/10000)%10 + n/100000){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}