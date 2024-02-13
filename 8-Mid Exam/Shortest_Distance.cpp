#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
    long long n, m;
    cin >> n >> m;
    long long dis[n+1][n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 1e18;
            if (i == j)
            {
                dis[i][j] = 0;
            }
        }
    }
    while (m--)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        if (dis[u][v] > w)
        {
            dis[u][v] = w;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {

                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    long long q;
    cin >> q;
    while (q--)
    {
        long long u, v;
        cin >> u >> v;
        if (dis[u][v] == 1e18)
        {
            cout <<"-1" << endl;
        }
        else
        {
            cout << dis[u][v] << endl;
        }
    }
    return 0;
}
