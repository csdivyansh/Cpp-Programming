#include<iostream>
#include<limits.h>
using namespace std;

int main()
{   
    int n;
    cin >> n;
    int arr[n];
    int maxx = INT_MIN;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        maxx = max(x, maxx);
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        count += maxx - arr[i];
    }
    cout << count;
    return 0;
}
