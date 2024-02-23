#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int>v[N];
bool vis[N];
int dis[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int c:v[parent])
        {
            if(!vis[c])
            {
                vis[c]=true;
                dis[c] = dis[parent]+1;
                q.push(c);
            }
        }
    }
}
int main()
{
    int n,s;
    cin>>n>>s;
    int mat[n+1][n+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<pair<int,int>>edge;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(mat[i][j]==1 && i!=j)
            {
                edge.push_back({i,j});
            }
        }
    }
    for(pair<int,int> val:edge)
    {
        v[val.first].push_back(val.second);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    bfs(s);
    for(int i=1; i<=n; i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}