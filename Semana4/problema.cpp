#include <iostream>
#include <array>
using namespace std;
#define tamanho 12
int grafo[tamanho][tamanho];
int best = 10000000;
int m, n;
int connected[tamanho];
int deg[tamanho];
int k;
int a = 0;
int no1, no2, custo;
int numero = 0;
void imprime(int valor);
void Funcao(int V, int custo);
int main()
{
    // n m k
    while (cin >> n >> m >> k)
    {
        best = 10000000;
        for (int c = 0; c < n; c++)
        {
            for (int l = 0; l < n; l++)
            {
                grafo[l][c] = -1;
            }
        }
        for (int i = 0; i < m; i++)
        {

            cin >> no1 >> no2 >> custo;
            grafo[no1 - 1][no2 - 1] = custo;
            grafo[no2 - 1][no1 - 1] = custo;
            deg[no1 - 1] = 0;
            connected[no1 - 1] = false;
            connected[no2 - 1] = false;
            deg[no2 - 1] = 0;

            connected[1] = true;
        }

        Funcao(0, 0);
        if (best != 10000000)
        {
            printf("%d\n", best);
        }
        else
        {
            printf("NO WAY!\n");
        }
    }
}

void Funcao(int V, int custo)
{

    if (custo >= best)
    {
        return;
    }
    if (V == n - 1)
    {
        best = custo;
    }
    for (int i = 0; i < n; i++)
    {

        if (connected[i] == true && deg[i] < k)
        {
            for (int j = 0; j < n; j++)
            {
                if (connected[j] == false && grafo[i][j] >= 0)
                {

                    deg[i] += 1;
                    deg[j] += 1;
                    connected[j] = true;

                    Funcao(V + 1, custo + grafo[i][j]);
                    deg[i] -= 1;
                    deg[j] -= 1;
                    connected[j] = false;
                }
            }
        }
    }
}
