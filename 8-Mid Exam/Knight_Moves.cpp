#include<bits/stdc++.h>
using namespace std;
bool vis[105][105];
int dis[105][105];
vector<pair<int,int>> d ={{-2,-1},{-2,+1},{-1,-2},{-1,+2},{+1,-2},{+1,+2},{+2,+1},{+2,-1}};
int n,m;
char a[105][105];
bool valid(int i, int j)
{
    if(i<0 || i >= n || j<0 || j>= m)
    {
        return false;
    } 
    else return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while(!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for(int i=0; i<8; i++)
        {
            int ci = a+d[i].first;
            int cj = b+d[i].second;
            if(valid(ci,cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                dis[ci][cj]=dis[a][b]+1;
            }
        }
    }
}
int main()
{
    int q;
    cin>>q;
    while (q--)
    {
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>>ki>>kj>>qi>>qj;
        memset(vis,false,sizeof(vis));
        memset(dis,-1,sizeof(dis));
        bfs(ki,kj);
        cout<<dis[qi][qj]<<endl;
    }
    return 0;
}