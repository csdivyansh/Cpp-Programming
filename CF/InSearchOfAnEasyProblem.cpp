#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            flag = true;
            break;
        }
    }
    if(flag) {
        cout << "HARD" << endl;
    } else {
        cout << "EASY" << endl;
    }
    return 0;
}