#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int maxx = 0;
        int count = 0;
        while(n--) {
            int x;
            cin >> x;
            if(x == 0) {
                count++;
                maxx = max(count, maxx);
            } else {
                count = 0;
            }
        }
        
        cout << maxx << endl;
        
    }
    return 0;
}