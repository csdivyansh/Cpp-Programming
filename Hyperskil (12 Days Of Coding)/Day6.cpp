#include <bits/stdc++.h>
using namespace std;

int main()
{
    string start_node;
    if (!getline(cin, start_node))
        return 0;

    map<string, vector<string>> adj;
    string line;
    while (getline(cin, line) && !line.empty())
    {
        size_t comma_pos = line.find(',');
        if (comma_pos != string::npos)
        {
            string u = line.substr(0, comma_pos);
            string v = line.substr(comma_pos + 1);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    map<string, int> dist;
    queue<string> q;

    dist[start_node] = 0;
    q.push(start_node);

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        for (size_t i = 0; i < adj[u].size(); ++i)
        {
            string v = adj[u][i];
            if (dist.find(v) == dist.end())
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    string furthest_node = start_node;
    int max_dist = -1;

    for (map<string, int>::iterator it = dist.begin(); it != dist.end(); ++it)
    {
        if (it->second > max_dist)
        {
            max_dist = it->second;
            furthest_node = it->first;
        }
    }

    cout << furthest_node;

    return 0;
}