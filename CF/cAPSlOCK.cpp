#include<iostream>
#include<string>
using namespace std;
string toUpperCase(string s) {
    for(int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}
string toLowerCase(string s) {
    for(int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool allRemainingAreUpper(string s) {
    bool allCaps = true;
    for(int i = 1; i < s.size(); i++) {
        if(!(s[i] >= 'A' && s[i] <= 'Z')) {
            allCaps = false;
            break;
        }
    }
    return allCaps;
}

int main() {
    string s;
    cin >> s;
    string x = s;
    if(toUpperCase(s) == x) {
        cout << toLowerCase(x);
        return 0;
    }

    if(s[0] >= 'a' && s[0] <= 'z' && allRemainingAreUpper(s)) {
        s = toLowerCase(s);
        s[0] = toupper(s[0]);
        cout << s;
        return 0;
    }

    cout << s;
    
    return 0;
}