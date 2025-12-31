#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    map<string, int> degrees;

    while (getline(cin, line))
    {
        size_t comma_pos = line.find(',');
        if (comma_pos != string::npos)
        {
            string u = line.substr(0, comma_pos);
            string v = line.substr(comma_pos + 1);
            degrees[u]++;
            degrees[v]++;
        }
    }

    int odd = 0;
    for (auto const &pair : degrees)
    {
        if (pair.second % 2 != 0)
        {
            odd++;
        }
    }

    if (odd <= 2)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (odd / 2) - 1 << endl;
    }

    return 0;
}