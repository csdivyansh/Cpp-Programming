#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    vector<pair<int, int>> arr;
    char comma;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> comma >> y;
        arr.push_back({x, y});
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x1 = arr[i].first;
        int y1 = arr[i].second;
        for (int j = i + 1; j < n; j++)
        {
            int x2 = arr[j].first;
            int y2 = arr[j].second;
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}