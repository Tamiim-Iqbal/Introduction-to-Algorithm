#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];
int level[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        //cout<<parent<<endl;
        for(int child:v[parent])
        {
            //cout<<child<<endl;
            if(visited[child]==false)
            {
                q.push(child);
                visited[child]=true;
                level[child]=level[parent]+1;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int source;
    cin>>source;
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    bfs(source);
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}