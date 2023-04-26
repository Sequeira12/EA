#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> G;
vector<int> dfs;
vector<int> low;
vector<int> parent;
vector<bool> visited;
vector<bool> articulation_points;
int timee = 0;

void AP(int v)
{
    int children = 0;
    visited[v] = true;
    dfs[v] = low[v] = ++timee;
    for (int w = 1; w < G.size(); w++)
    {
        if (G[v][w])
        {
            if (!visited[w])
            {
                children++;
                parent[w] = v;
                AP(w);
                low[v] = min(low[v], low[w]);
                if (parent[v] == 0 && children > 1)
                {
                    articulation_points[v] = true;
                }
                if (parent[v] != 0 && low[w] >= dfs[v])
                {
                    articulation_points[v] = true;
                }
            }
            else if (w != parent[v])
            {
                low[v] = min(low[v], dfs[w]);
            }
        }
    }
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        G = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        dfs = vector<int>(n + 1, 0);
        low = vector<int>(n + 1, 0);
        parent = vector<int>(n + 1, 0);
        visited = vector<bool>(n + 1, false);
        articulation_points = vector<bool>(n + 1, false);
        timee = 0;

        int v, w;
        while (cin >> v && v != 0)
        {
            while (cin.get() != '\n')
            {
                cin >> w;
                G[v][w] = 1;
                G[w][v] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                AP(i);
            }
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (articulation_points[i])
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
