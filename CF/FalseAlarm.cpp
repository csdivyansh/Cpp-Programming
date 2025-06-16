#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int count = 0;
        int start = 0;
        int n, x;
        cin >> n >> x;

        int arr[n];

        for(int i = 0; i < n; i++) {
            int d;
            cin >> d;
            if(d == 1) {
                if(count == 0) start = i;
                count++;                
            }
            arr[i] = d;
        }

        if(n <= x) {
            cout << "YES" << endl;
        } else {
            bool flag = true;
            start = start + x; 
            // cout << start;
            while(start < n) {
                if(arr[start] == 1) {
                    flag = false;
                }
                start++;
            }            
            cout << (flag? "YES" : "NO" ) << endl;

        }
    }
    return 0;
}
