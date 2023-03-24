
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, p1, p2;
int valorReal = 0;
int help;
int k;
int N;
int best = 0;
vector<vector<bool>> g;

int ub(int i, vector<bool> &x, int contador)
{
    for (int j = i; j <= N - 1; j++)
    {

        bool b = true;
        for (int k = 0; k <= i - 1; k++)
        {
            if (x[k] == true and g[j][k] == true)
            {
                b = false;
                break;
            }
        }
        if (b == true)
        {

            contador += 1;
        }
    }
    return contador;
}

void F(int i, vector<bool> &x, int contador)
{

    if (i == N)
    {
        if (contador > best)
        {
            best = contador;
        }
        return;
    }
    if (ub(i, x, contador) <= best)
    {
        return;
    }

    x[i] = false;
    F(i + 1, x, contador);
    bool b = true;
    for (int j = 0; j <= i - 1; j++)
    {

        if (x[j] == true and g[i][j] == true)
        {
            b = false;
            return;
        }
    }
    if (b == true)
    {
        x[i] = true;

        F(i + 1, x, contador + 1);
    }
}

int main()
{

    cin >> N >> m;

    vector<bool> x = vector<bool>(N, false);
    g = vector<vector<bool>>(N, vector<bool>(N, false));
    while (m > 0)
    {

        cin >> p1 >> p2;
        g[p1][p2] = true;
        g[p2][p1] = true;
        m--;
    }

    F(0, x, 0);

    cout << best << endl;
}
