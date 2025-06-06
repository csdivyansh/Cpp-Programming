#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int r, c;
    cin >> r >> c;
    bool turn = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(i % 2 == 0) {
                cout << "#";
            } else if (turn) {
                if(j == 0) cout << '#';
                else cout << '.'; 
            } else {
                if(j == c - 1) cout << '#';
                else cout << '.';
            }
        }
        if(i % 2 == 1) turn = !turn;
        cout << endl;
    }
    return 0;
}
