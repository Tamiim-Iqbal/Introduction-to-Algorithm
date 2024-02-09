#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
bool pathVis[N];
bool ans ;
void dfs(int p)
{
    vis[p] = true;
    pathVis[p]=true;
    for(int c: v[p])
    {
        
        if(pathVis[c])
        {
            ans = true;
        }
        if(vis[c]==false)
        {
            dfs(c);   
        }
    }
    //kaj sesh parent er
    pathVis[p]=false;
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
    }
    memset(vis,false,sizeof(vis));
    memset(pathVis,false,sizeof(pathVis));
    ans = false;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        } 
    }
    if(ans) cout<<"Cycle found";
    else cout<<"Cycle not found";
    return 0;
}