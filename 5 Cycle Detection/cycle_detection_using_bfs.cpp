#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
int par[N];
bool ans ;
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        //cout<<p<<" ";
        for(int c:v[p])
        {
            par[c]=p;
                if(vis[c]==true && par[p] != c)
            {
                ans = true;
            }
            if(vis[c]==false)
            {
                vis[c]=true;
                q.push(c);
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
    memset(par,-1,sizeof(par));
    ans = false;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            bfs(i);
        } 
    }
    if(ans) cout<<"Cycle found";
    else cout<<"Cycle not found";
    return 0;
}