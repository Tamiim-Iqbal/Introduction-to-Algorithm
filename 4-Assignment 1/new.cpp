#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[20][20];
bool vis[20][20];
vector<pair<int, int> >v = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid (int i, int j)
{
    if (i<0 || i>=n || j<0 || j>= m) return false;
    else return true ;//else use na krleo hbe
}
void dfs (int si, int sj)
{
    //cout<<si<<" "<<sj<<endl;
    cout<<a[si][sj]<<" ";
    vis[si][sj]=true;
    for(int i=0; i<4; i++)
    {
        int ci = si+v[i].first;
        int cj = sj+v[i].second;
        if (valid(ci,cj)==true && vis[ci][cj]==false)
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
    int si,sj;
    cin>>si>>sj;
    dfs(si,sj);
    return 0;
}