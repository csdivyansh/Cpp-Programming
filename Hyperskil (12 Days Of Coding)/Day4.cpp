#include <bits/stdc++.h>
using namespace std;

int main()
{
    string fork1 = "";
    string fork2 = "";
    string fork3 = "";
    string fork4 = "";

    int ans = 0;
    string str;
    
    while (getline(cin, str))
    {
        int count = 0;
        string person = "";
        string action = "";
        int fork = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ',')
            {
                count++;
                continue;
            }
            if (count == 0)
                person += str[i];
            else if (count == 1)
                action += str[i];
            else
                fork = str[i] - '0';
        }

        if (action == "pick")
        {
            if (fork == 1)
            {
                if(fork1 == "") {
                    fork1 = person;
                } else {
                    ans++;
                }
            }
            if (fork == 2)
            {
                if (fork2 == "")
                {
                    fork2 = person;
                }
                else
                {
                    ans++;
                }
            }
            if (fork == 3)
            {
                if (fork3 == "")
                {
                    fork3 = person;
                }
                else
                {
                    ans++;
                }
            }
            if (fork == 4)
            {
                if (fork4 == "")
                {
                    fork4 = person;
                }
                else
                {
                    ans++;
                }
            }
        } else if(action == "release") {
            if(fork == 1)
                fork1 = "";
            else if (fork == 2)
                fork2 = "";
            else if (fork == 3)
                fork3 = "";
            else if (fork == 4)
                fork4 = "";
        }
    }
    cout << ans << endl;
    return 0;
}