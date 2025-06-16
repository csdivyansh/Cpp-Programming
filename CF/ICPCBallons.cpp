#include<bits/stdc++.h>
using namespace std;

int main() {    
    int t;
    cin >> t;
    while(t--) {
        set<char> st;
        int n;
        string s;
        cin >> n >> s;
        int count = 0;
        for(char ch : s) {
            if(st.find(ch) != st.end()){
                count++;
            } else {
                count+=2;
                st.insert(ch);
            }
        }
        cout << count << endl;
    }
}