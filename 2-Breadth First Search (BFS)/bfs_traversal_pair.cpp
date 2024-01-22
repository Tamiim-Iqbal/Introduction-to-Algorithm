#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];
int level[1005];
void bfs(int src,int des)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    visited[src]=true;
    bool flag = false;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        //cout<<parent<<endl;
        int parent = p.first;
        int level = p.second;
        if(parent == des)
        {
            cout<<level<<endl;
            flag = true;
        }
        for(int child:v[parent])
        {
            //cout<<child<<endl;
            if(visited[child]==false)
            {
                q.push({child,level+1});
                visited[child]=true;
            }
        }
    }
    if(flag == false)
    {
        cout<<"-1"<<endl;
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
    bfs(source,5);
    return 0;
}