#include<bits/stdc++.h>
#define pi pair<ll,ll>
#define ll long long
using namespace std;
const ll N = 1e5+5;
vector<pi> v[N];
ll dis[N];
ll parent[N];
class cmp
{
    public:
        bool operator()(pi a, pi b)
        {
            return a.second>b.second;
        }
};
void dijkstra(int s)
{
    priority_queue<pi,vector<pi>,cmp> q;
    q.push({s,0});
    dis[s]=0;
    while(!q.empty())
    {
        pi par = q.top();
        q.pop();
        ll parNode = par.first;
        ll parCost = par.second;
        for(pi child: v[parNode])
        {
            ll cNode = child.first;
            ll cCost = child.second;
            if(parCost+cCost < dis[cNode])
            {
                dis[cNode] = parCost+cCost;
                q.push({cNode,dis[cNode]});
                parent[cNode] = parNode;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    dijkstra(1);
    if(dis[n] == 1e18) cout<<"-1";
    else 
    {
        ll x = n;
        vector<ll>path;
        while(x!=-1)
        {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(),path.end());
        for(ll val: path) cout<<val<<" ";
    }
    return 0;
}