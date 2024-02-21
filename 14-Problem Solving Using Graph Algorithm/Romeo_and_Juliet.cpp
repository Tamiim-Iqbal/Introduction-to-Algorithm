#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
int dis[N];
bool vis[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    dis[s]=0;
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
    memset(dis,-1,sizeof(dis));
    memset(vis,false,sizeof(vis));
    int src,d,k;
    cin>>src>>d>>k;
    bfs(src);
    if(dis[d]!= -1 && dis[d]<= k*2) cout<<"YES";
    else cout<<"NO";
    return 0;
}