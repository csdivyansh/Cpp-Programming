#include <iostream>
using namespace std;

int solve(long long x) {
    if (x == 0) return 0;
    
    long long a = 0, b = 1;
    int count = 1;
    
    while (b < x) {
        a = b;
        b = c;
        count++;
    }
    
    return 2 * count + 1;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x;
        cin >> x;
        cout << solve(x) << "\n";
    }
    
    return 0;
}