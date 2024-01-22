#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool visited[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout<<parent<<endl;
        for(int child:v[parent])
        {
            //cout<<child<<endl;
            if(visited[child]==false)
            {
                q.push(child);
                visited[child]=true;
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
    bfs(source);
    return 0;
}