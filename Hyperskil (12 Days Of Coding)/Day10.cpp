#include <bits/stdc++.h>
using namespace std;

string removeCommas(string s)
{
    string res = "";
    for (char c : s)
    {
        if (c != ',')
            res += c;
    }
    return res;
}

int main()
{
    int n = 10;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        arr[i] = removeCommas(s);
    }

    string first = arr[0];
    int len = first.length();

    for (int l = len; l > 0; l--)
    {
        for (int i = 0; i <= len - l; i++)
        {
            string sub = first.substr(i, l);
            bool allMatch = true;

            for (int j = 1; j < n; j++)
            {
                if (arr[j].find(sub) == string::npos)
                {
                    allMatch = false;
                    break;
                }
            }

            if (allMatch)
            {
                cout << l << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}