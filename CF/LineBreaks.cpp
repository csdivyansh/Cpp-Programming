#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, count = 0;
        cin >> n >> m;
        bool stop = false;
        while (n--) {
            string s;
            cin >> s;
            if(stop || s.size() > m) {
                stop = true;
                continue;
            }
            if (s.size() <= m) {
                count++;
                m -= s.size();
            }
        }
        cout << count << endl;
    }
    return 0;
}