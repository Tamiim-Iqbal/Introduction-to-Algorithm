#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
vector<pair<long long, long long>> v[N];
int dis[N];
class cmp
{
    public:
        bool operator()(pair<long long, long long> a, pair<long long, long long> b) 
        {
            return a.second > b.second;
        }
};
void dijkstra(int s)
{
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, cmp> q;
    q.push({s,0});
    dis[s]=0;
    while(!q.empty())
    {
        pair<long long,long> par = q.top();
        q.pop();
        long long node = par.first;
        long long cost = par.second;
        for(pair<long long,long long> child: v[node])
        {
            long long childNode = child.first;
            long long childCost = child.second;
            
            if(cost+childCost < dis[childNode])
            {
                //path relax
                dis[childNode] = cost+childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    long long n,e;
    cin>>n>>e;
    while (e--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i]=INT_MAX;
    }
    long long s,q;
    cin>>s>>q;
    dijkstra(s);
    // for(int i=1; i<=n; i++)
    // {
    //     cout<<i<<"-> "<<dis[i]<<endl;
    // }
    while(q--)
    {
        long long d,c;
        cin>>d>>c;
        if(dis[d]<=c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}