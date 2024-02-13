#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6+5;
const long long INF = 1e18;
class Edge {
public:
    long long u;
    long long v;
    long long c;
    Edge (long long u, long long v, long long c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
long long dis[N];
int main()
{
    long long n, e;
    cin>>n>>e;
    vector<Edge>edgeList;
    while (e--) 
    {
        long long u,v,c;
        cin >> u >> v >> c;
        edgeList.push_back(Edge(u, v, c));
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = INF; 
    }
    long long s;
    cin >> s;
    dis[s] = 0;
    for(int i = 1; i <= n - 1; i++) {
        for(Edge ed: edgeList) {
            long long u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if(dis[u] != INF && dis[u] + c < dis[v]) 
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for(Edge ed: edgeList) 
    {
        long long u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if(dis[u] != INF && dis[u] + c < dis[v]) 
        {
            cycle = true;
            break;
        }
    }
    if(cycle) cout << "Negative Cycle Detected"<<endl;
    else 
    {
        long long q;
        cin >> q;
        while(q--) 
        {
            long long n;
            cin >> n;
            if(dis[n] < INF) cout<<dis[n]<<endl;
            else cout<<"Not Possible"<<endl;
        }
    }
    return 0;
}
