#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    map<T, list<T>> adj;

    void addEdge(T u, T v, bool isdirected)
    {
        // create an edge from u to v;
        adj[u].push_back(v);

        if (!isdirected)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // for connected graph with no components
    void bfs()
    {
        unordered_map<T, bool> visited;
        vector<T> ans;
        queue<T> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            T front = q.front();
            q.pop();

            ans.push_back(front);

            for (auto &i : adj[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        for (int &i : ans)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    Graph<int> g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    cout << endl;
    cout << "Adjacency List ->" << endl;
    g.printAdjList();
    cout << endl;
    cout << "BFS Traversal ->" << endl;
    g.bfs();
    cout << endl;
    return 0;
}