#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    char op;
    cout << "Enter a: ";
    cin >> a;
    cout << endl << "Enter b: ";
    cin >> b;
    cout << endl << "Enter operation: ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    case '%':
        cout << a % b;
        break;
    
    default:
        cout << "Enter a valid operator";
        break;
    }

    return 0;
};