#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>v[N];
bool vis[N];
int dis[N];
int par[N];
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
                par[c]=parent;
                q.push(c);
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    int s,d;
    cin>>s>>d;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    memset(par,-1,sizeof(par));
    bfs(s);
    cout<<dis[d]<<endl;
    vector<int>path;
    int x = d;
    while (x != -1)
    {
        //cout<<x<<" ";
        path.push_back(x);
        x = par[x];
    }
    reverse(path.begin(),path.end());
    for (int val:path)
    {
        cout<<val<<" ";
    }
    return 0;
}