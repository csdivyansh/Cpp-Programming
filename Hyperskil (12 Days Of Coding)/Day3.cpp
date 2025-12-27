#include <bits/stdc++.h>
using namespace std;

bool lowercase(string &password)
{
    for (char c : password)
    {
        if (c >= 'a' && c <= 'z')
            return true;
    }
    return false;
}

bool uppercase(string &password)
{
    for (char c : password)
    {
        if (c >= 'A' && c <= 'Z')
            return true;
    }
    return false;
}

bool digit(string &password)
{
    for (char c : password)
    {
        if (c >= '0' && c <= '9')
            return true;
    }
    return false;
}

bool special_symbol(string &password)
{
    string specials = "!@#$%^&*";
    for (char c : password)
    {
        if (specials.find(c) != string::npos)
            return true;
    }
    return false;
}

int repeated(string &password)
{
    if (password.empty())
        return 0;
    map<char, int> freq;
    int mxfreq = 0;
    for (char ch : password)
    {
        freq[ch]++;
        mxfreq = max(mxfreq, freq[ch]);
    }
    if ((mxfreq * 100.0) / password.size() >= 30.0)
        return mxfreq;
    return 0;
}

int main()
{
    int n = 50;
    vector<string> passwords(n);
    vector<double> scores(n);
    for (int i = 0; i < n; i++)
    {
        if (!(cin >> passwords[i]))
            break;
        scores[i] = (double)passwords[i].size();
    }

    for (int i = 0; i < n; i++)
    {
        string password = passwords[i];
        double score = scores[i];

        if (!lowercase(password))
            score *= 0.75;
        if (!uppercase(password))
            score *= 0.75;
        if (!digit(password))
            score *= 0.75;
        if (!special_symbol(password))
            score *= 0.75;

        int check = repeated(password);
        if (check)
            score -= (double)check;
        scores[i] = score;
    }

    double max_score = -1e18;
    for (int i = 0; i < n; i++)
    {
        max_score = max(max_score, scores[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (scores[i] == max_score)
        {
            cout << passwords[i] << endl;
            break;
        }
    }

    return 0;
}