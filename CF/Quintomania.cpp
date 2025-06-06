#include<iostream>
#include<cmath>
using namespace std;
int main(int argc, char const *argv[]) {
    int t = 0;
    cin >> t;
    while(t-- > 0) {
        int n = 0;
        cin >> n;
        int x = 0;
        cin >> x;
        bool flag = true;
        for(int i = 1; i < n; i++) {
            int y;
            cin >> y;
            if(!(abs(x - y) == 5 || abs(x - y) == 7)) {
                flag = false;
            }
            x = y;
        }
        if(flag)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}