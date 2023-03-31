
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
}

int main()
{

    cin >> N >> m;

    vector<bool> x = vector<bool>(N, false);
    g = vector<vector<bool>>(N, vector<bool>(N, false));
}
