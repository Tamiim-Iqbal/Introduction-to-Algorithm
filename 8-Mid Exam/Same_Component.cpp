#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char a[N][N];
bool vis[N][N];
int n,m;
vector<pair<int,int>>d = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>= m)
    {
        return false;
    }
    else return true;   //else use na krleo hbe, if true hole seta thekei return hbe
}
void dfs(int si, int sj)
{
    if(a[si][sj]=='-') return;
    vis[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si+d[i].first;
        int cj = sj+d[i].second;
        //if (valid(ci,cj) == true && !vis[ci][cj] == false)
        if (valid(ci,cj) && !vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    dfs(si,sj);
    if(vis[di][dj]==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}