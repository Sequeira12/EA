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
int n;
vector<pair<int, int>> coords;
stack<pair<int, int>> S;

pair<int, int> BottomMost()
{
    pair<int, int> bot = coords[0];
    for (pair<int, int> v : coords)
    {
        if (v.second < bot.second)
        {
            bot = v;
        }
        else if (v.second == bot.second)
        {
            bot = v;
        }
    }
    return bot;
}

int CW(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    int area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}
pair<int, int> nextToTop(stack<pair<int, int>> &S)
{
    pair<int, int> p = S.top();
    S.pop();
    pair<int, int> res = S.top();
    S.push(p);
    return res;
}

void F()
{
    pair<int, int> find = BottomMost();

    sort(coords.begin() + 1, coords.end(), [find](pair<int, int> p1, pair<int, int> p2)
         { return CW(find, p1, p2); });

    S.push(find);
    S.push(coords[1]);

    for (int i = 2; i < n; i++)
    {

        while (CW(nextToTop(S), S.top(), coords[i]) < 0)
        {
            S.pop();
        }
        S.push(coords[i]);
    }
    printf("|%lu|\n", S.size());
}

int main()
{
    int x, y;
    while (cin >> n)
    {

        if (n == 0)
        {
            break;
        }
        coords.clear();
        pair<int, int> cordenadas;
        for (int i = 0; i < n; i++)
        {
            cin >> cordenadas.first >> cordenadas.second;
            coords.push_back(cordenadas);
        }
        F();
    }

    return 0;
}
