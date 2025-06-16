#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    string x = "";
    for(int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        if((9 - digit) < digit) {
            x += (9 - digit) + '0';
        } else {
            x += s[i];
        }
    }
    if(s[0] == '9') {
        x[0] = '9';
    }
    cout << x;
    return 0;
}
