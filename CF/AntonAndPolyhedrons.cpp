#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    int total = 0;
    while(t--) {
        string s;
        cin >> s;
        
        if(s == "Tetrahedron") {
            total += 4;
        } else if(s == "Cube") {
            total += 6;
        } else if(s == "Octahedron") {
            total += 8;
        } else if(s == "Dodecahedron") {
            total += 12;
        } else if(s == "Icosahedron") {
            total += 20;
        }
    }
    cout << total;
    return 0;
}
