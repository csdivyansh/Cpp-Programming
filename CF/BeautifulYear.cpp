#include<iostream>
using namespace std;

bool isDistinct(int n) {
    int first = n % 10;
    int second =  (n / 10) % 10;
    int third = (n / 100) % 10;
    int fourth = n/1000;
    
    return first != second && first != third && first != fourth
    && second != third && second != fourth && third != fourth; 
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    n++;
    while(n <= 9012) {
        if(isDistinct(n)) {
            cout << n;
            break;
        }
        n++;
    }
    return 0;
}
