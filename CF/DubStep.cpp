#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            if(j != 0) {
                cout << ' ';
                j = 0;
            }
            i += 2;
        } else {
            j++;
            cout << s[i];
        }
    }
    return 0;
}