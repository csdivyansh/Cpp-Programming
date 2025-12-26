#include <bits/stdc++.h>
using namespace std;
int main()
{
    int target;
    cin >> target;
    vector<int> a;
    string s;
    cin >> s;
    stringstream ss(s);
    string str;
    while (getline(ss, str, ','))
    {
        int num = stoi(str);
        a.push_back(num);
    }
    double ans = 0;
    int dis = INT_MAX;
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double avg = (a[i] + a[j]) / 2;
            if (abs(target - avg) < dis)
            {
                ans = ceil(avg);
                dis = abs(target - avg);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
