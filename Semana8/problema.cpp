
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m, p1, p2;
int N;

int vis = 0;
vector<vector<int>> g;

vector<int> color;

bool colorir(int u)
{

    stack<int>
        s;

    color[u] = 1;
    s.push(u);

    while (s.size() > 0)
    {
        int k = s.top();
        s.pop();

        for (int v = 1; v <= N; v++)
        {

            if (g[k][v] == 1)
            {

                if (color[v] == 0)
                {
                    color[v] = (color[k] % 2) + 1;
                    s.push(v);
                }
                else if (color[k] == color[v] && k != v)
                {

                    return false;
                }
            }
        }
    }
    return true;
}

bool F(int N)
{

    for (int i = 1; i <= N; i++)
    {

        if (color[i] == 0)
        {

            if (colorir(i) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    while (cin >> N >> m)
    {

        g = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
        color = vector<int>(N + 1, 0);

        while (m--)
        {
            cin >> p1 >> p2;
            g[p1][p2] = 1;
            g[p2][p1] = 1;
        }

        if (F(N))
        {
            cout << "NOT SURE\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
