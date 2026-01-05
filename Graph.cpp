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
private:
    T V, E;

    map<T, list<T>> adj;

public:
    Graph(T V, T E)
    {
        this->V = V;
        this->E = E;
    }
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
                cout << j << " ";
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

        for (T &i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    void dfs_helper(T node, unordered_map<T, bool> &visited, vector<T> &component)
    {
        component.push_back(node);
        visited[node] = true;

        for (T &nbr : adj[node])
        {
            if (!visited[nbr])
                dfs_helper(nbr, visited, component);
        }
    }
    void dfs()
    {
        unordered_map<T, bool> visited;
        vector<vector<T>> ans;
        for (T i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                vector<T> component;
                dfs_helper(i, visited, component);
                ans.push_back(component);
            }
        }
        int count = 1;
        for (auto &c : ans)
        {
            cout << "Component : " << count << " -> " << endl;
            count++;
            for (auto &i : c)
            {
                cout << i << " ";
            }
            cout << endl;
        }
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

    Graph<int> g(n, m);

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
    cout << "DFS Traversal ->" << endl;
    g.dfs();
    cout << endl;

    /*
    Enter the number of nodes :
    8
    Enter the number of edges :
    8
    0 2
    2 1
    1 3
    4 3
    2 4
    5 6
    5 7
    6 7

    Adjacency List ->
    0 -> 2
    1 -> 2 3
    2 -> 0 1 4
    3 -> 1 4
    4 -> 3 2
    5 -> 6 7
    6 -> 5 7
    7 -> 5 6

    BFS Traversal ->
    0 2 1 4 3

    DFS Traversal ->
    Component : 1 ->
    0 2 1 3 4
    Component : 2 ->
    5 6 7
    */
    return 0;
}