#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> par;
vector<vector<int>> G;

const int infinito = INT_MAX;

int dijkstra(int n, int dest, vector<vector<int>> &G)
{
    vector<int> dist(n, infinito);
    priority_queue<par, vector<par>, greater<par>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++)
        {
            int w = G[u][v];
            if (w >= 0 && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dest];
}

int main()
{
    int number, ids;
    cin >> number >> ids;
    vector<vector<int>> G(number, vector<int>(number));

    for (int i = 0; i < number; i++)
    {
        int id;
        cin >> id;
        for (int j = 0; j < number; j++)
        {
            cin >> G[i][j];
        }
    }

    int custo = dijkstra(number, ids - 1, G);
    cout << custo << endl;

    return 0;
}
