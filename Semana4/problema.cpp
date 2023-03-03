
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m, n;

int k;
int F(vector<vector<int>> &dp, vector<vector<int>> &M);
int main()
{
    // n m k
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;

        vector<vector<int>> M;
        M = vector<vector<int>>(m + 1, vector<int>(m + 1, 0));
        vector<vector<int>> dp;
        dp = vector<vector<int>>(m + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j <= i; j++)
            {
                cin >> k;

                M[i][j] = k;
                dp[i][j] = 0;
            }
        }

        for (int j = 0; j < m + 1; j++)
        {
            M[m][j] = 0;
            dp[m][j] = 0;
        }

        int a = F(dp, M);
        cout << a << endl;
    }
}

int F(vector<vector<int>> &dp, vector<vector<int>> &M)
{
    for (int k = m - 1; k >= 0; k--)
    {
        for (int j = 0; j <= k; j++)
        {
            // printf("%d %d\n", k, j);
            dp[k][j] = M[k][j] + max(dp[k + 1][j], dp[k + 1][j + 1]);
        }
    }
    return dp[0][0];
}