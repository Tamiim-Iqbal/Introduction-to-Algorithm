#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int>v[N];
bool vis[N];
int dis[N];
int parent[N];
vector<int>ans;
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    dis[s]=1;
    vis[s]=true;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int c: v[par])
        {
            if(!vis[c])
            {
                vis[c] = true;
                q.push(c);
                dis[c] = dis[par]+1;
                parent[c]=par;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if (dis[n]==-1) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        cout<<dis[n]<<endl;
        int x = n;
        vector<int>path;
        while(x!=-1)
        {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(),path.end());
        for(int val: path) cout<<val<<" ";
    }
    return 0;
}