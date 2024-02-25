#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char a[N][N];
bool vis[N][N];
pair<int,int> parent[N][N];
int n,m;
vector<pair<int, int>> d= {{0, 1},{0, -1},{-1, 0},{1, 0}};
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first;
        int pj = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {pi,pj};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj;
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
                {
                    si = i;
                    sj = j;
                }
            if (a[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
            //parent[i][j]={-1,-1};
        }
    }
    memset(parent,-1,sizeof(parent));
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    pair<int,int> src = {-1,-1};
    pair<int,int> des = {di,dj};
    while(des != src)
    {
        a[des.first][des.second] = 'X';
        des = {parent[des.first][des.second]};
    }
    a[si][sj] = 'R';
    a[di][dj] = 'D';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}


