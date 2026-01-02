#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20;

int main()
{
    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line);
        for (int j = 0; j < N; ++j)
        {
            ss >> grid[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(N, vector<int>(N, INF));

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty())
    {
        int d = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (d > dist[r][c])
            continue;
        if (r == N - 1 && c == N - 1)
            break;

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N)
            {
                if (dist[r][c] + grid[nr][nc] < dist[nr][nc])
                {
                    dist[nr][nc] = dist[r][c] + grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }

    cout << dist[N - 1][N - 1] << endl;

    return 0;
}