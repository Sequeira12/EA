
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int casos, N, M;
int valorReal = 0;
int help;
int k;
int F(vector<vector<bool>> &dp, int soma, int tam, vector<int> &valores);
int main()
{
    // n m k

    while (cin >> casos)
    {
        vector<int> position;

        for (int i = 0; i < casos; i++)
        {
            cin >> N >> M;
            vector<int> position(N, 0);
            for (int k = 0; k < N; k++)
            {
                cin >> help;
                position[k] = help;
            }
            vector<bool> positionProtected(N, false);
            sort(position.begin(), position.end());
            int contadorGuardas = 0;
            for (int l = 0; l < position.size(); l++)
            {
                if (positionProtected[l] == false)
                {

                    positionProtected[l] = true;
                    int valor = position[l] + 2 * M;
                    for (int a = l; a < position.size(); a++)
                    {
                        if (position[a] <= valor)
                        {
                            positionProtected[a] = true;
                        }
                    }

                    contadorGuardas++;
                }
            }
            cout << contadorGuardas << endl;
        };
    }
}
