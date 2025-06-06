#include <iostream>
using namespace std;

int update(int a){
    a-=5;
    return a;
}
int main(int argc, char const *argv[])
{
    int a = 15;
    update(a);
    cout << a;
    
    return 0;
};
