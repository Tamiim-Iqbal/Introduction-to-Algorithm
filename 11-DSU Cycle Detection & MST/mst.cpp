#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
void dsu_initialization(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find (int node)
{
    if(par[node] == -1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge
{
    public:
        int u,v,c;
        Edge(int u, int v, int c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialization(n);
    vector<Edge>edgeList;
    while (e--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edgeList.push_back(Edge(a,b,c));
    }
    sort(edgeList.begin(), edgeList.end(),cmp);
    int ans=0;
    for(Edge a: edgeList)
    {
        //cout<<a.u<<" "<<a.v<<" "<<a.c<<endl; 
        int leaderA = dsu_find(a.u);
        int leaderB = dsu_find(a.v);
        if(leaderA != leaderB)
        {
            dsu_union_by_size(a.u,a.v);
            ans += a.c;
        }   
        //else continue;   // na dileo hbe
    }
    cout<<ans;
    return 0;
}