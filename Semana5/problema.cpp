
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;
int valorReal = 0;

int k;
int F(vector<vector<bool>> &dp, int soma, int tam, vector<int> &valores);
int main()
{
    // n m k

    while (cin >> m)
    {
        int soma = 0;
        vector<int> valores;
        valores = vector<int>(m + 1, 0);
        for (int i = 0; i < m; i++)
        {

            cin >> n;

            valores[i + 1] = n;
            soma += n;
        }
        valorReal = soma;
        soma = soma / 2;

        vector<vector<bool>> dp;
        dp = vector<vector<bool>>(m + 1, vector<bool>(soma, false));

        dp[0][0] = true;
        k = F(dp, soma, m, valores);

        printf("%d\n", k);
    }
}

int F(vector<vector<bool>> &dp, int soma, int tam, vector<int> &valores)
{
    int i, j;
    int valor = 0;
    for (i = 1; i <= tam; i++)
    {
        for (j = 0; j <= soma; j++)
        {

            if (j < valores[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - valores[i]];
            }
            if (i == tam)
            {
                if (dp[i][j])
                {
                    valor = j;
                }
            }
        }
    }

    int outro = valorReal - valor;
    return abs(outro - valor);
}
