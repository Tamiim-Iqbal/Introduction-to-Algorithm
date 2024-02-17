#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialization(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}
int dsu_find (int node)
{
    if(par[node] == -1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void union_by_size(int node1, int node2)
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
void union_by_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(level[leaderA]>level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if(level[leaderA]<level[leaderB])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}
int main()
{
    dsu_initialization(7);
    union_by_level(1,2);
    union_by_level(2,3);
    union_by_level(4,5);
    union_by_level(5,6);
    // for(int i=0; i<=6; i++)
    // {
    //     cout<<dsu_find(i)<<" ";
    //     cout<<par[i]<<" ";
    // }
    cout<<dsu_find(1)<<" ";
    cout<<dsu_find(4)<<" ";
    union_by_level(1,4);
    cout<<endl;
    cout<<dsu_find(1)<<" ";
    cout<<dsu_find(4)<<" ";
    return 0;
}