#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 1;
    int prev;
    cin >> prev;
    n--;
    while(n--) {
        int x;
        cin >> x;
        if(x != prev) count++;
        prev = x;
    }
    cout << count;
    return 0;
}