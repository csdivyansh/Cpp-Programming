#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> x(10), y(10);
    char comma;
    for (int i = 0; i < 10; i++)
    {
        cin >> x[i] >> comma >> y[i];
    }
    double area = 0.0;
    for (int i = 0; i < 10; i++)
    {
        int j = (i + 1) % 10;
        area += (x[i] * y[j]) - (x[j] * y[i]);
    }
    cout << fixed << setprecision(2) << abs(area) / 2.0 << endl;
    return 0;
}