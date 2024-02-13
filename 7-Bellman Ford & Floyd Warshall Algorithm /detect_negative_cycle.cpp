#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dis[N];
class Edge
{
    public:
        int u;
        int v;
        int c;
        Edge(int u, int v, int c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> edgeList;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgeList.push_back(Edge(a,b,c));
        //edgeList.push_back(Edge(b,a,c)); //undirected
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0]=0; //source
    for (int i= 1; i<=n-1; i++)
    {
        for(Edge ed: edgeList)
        {
            //cout<<ed.u<<" "<<ed.v<<" "<<ed.c<< endl;
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if(dis[u]<INT_MAX && dis[u]+c < dis[v])
            {
                dis[v] = dis[u]+c;
            }
        }
    }
    bool cycle = false;
    for(Edge ed: edgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if(dis[u]<INT_MAX && dis[u]+c < dis[v])
            {
                cycle = true;
                break;
            }
        }
    if(cycle) cout<<"Cycle Detected. No answer";
    else
    {
        for(int i=0; i<n; i++)
        {
            cout<<i<<"->"<<dis[i]<<endl;
        }
    }
    return 0;
}