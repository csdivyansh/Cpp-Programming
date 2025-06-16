#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int recruits = 0;
    int untreated = 0;
    while(n--) {
        int x;
        cin >> x;

        if(x == -1 && recruits == 0) {
            untreated++;
        } else if(x == -1 && recruits > 0){
            recruits--;
        } else if(x > 0) {
            recruits += x;
        }
        
    }
    cout << untreated;
    return 0;
}
