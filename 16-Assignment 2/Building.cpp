#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5;
ll parent[N];
ll group_size[N];
void dsu_initialize(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        parent[i] = -1;
        group_size[i] =1;
    }
}
ll dsu_find(ll node)
{
    if(parent[node] == -1) return node;
    ll leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(ll node1, ll node2)
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);
    if(group_size[leaderA]>group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA]+= group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
class Edge
{
    public:
        ll u,v,w;
        Edge(ll u, ll v, ll w)
        {
            this->u = u;
            this->v = v;
            this->w = w;
        }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main()
{
    ll n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge>edgelist;
    ll totalcost = 0;
    while(e--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    ll count=0;
    sort(edgelist.begin(),edgelist.end(),cmp);
    for(Edge edge:edgelist)
    {
        ll leaderU = dsu_find(edge.u);
        ll leaderV = dsu_find(edge.v);
        if(leaderU == leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(edge.u,edge.v);
            totalcost += edge.w;
            count++;
        }
        
    }
    if(count == n-1)
        cout<<totalcost<<endl;
    else cout<<"-1"<<endl;
    return 0;
}