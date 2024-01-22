#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
int level[1005];
bool visited[1005];
int par[1005];
void bfs(int src,int des)
{
    queue<int>q;
    q.push(src);
    level[src]=0;
    visited[src]=true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child: v[parent])
        {
            if (visited[child]==false)
            {
                q.push(child);
                visited[child]=true;
                level[child]=level[parent]+1;
                par[child]=parent;
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
    memset(level,-1,sizeof(level));
    memset(visited,false,sizeof(visited));
    memset(par,-1,sizeof(par));
    int source,destination;
    cin>>source>>destination;
    bfs(source,destination);
    int x=destination;
    // stack<int>s;
    // while (x != -1)
    // {
    //     //cout<<x<<" ";
    //     s.push(x);
    //     x = par[x];
    // }
    // // while(!s.empty())
    // // {
    // //     cout<<s.top()<<" ";
    // //     s.pop();
    // // }

    vector<int>path;
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