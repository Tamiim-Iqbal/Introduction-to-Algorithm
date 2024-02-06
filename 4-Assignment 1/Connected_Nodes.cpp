#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>v[1000];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        vector<int>ans;
        for(int i=0; i<v[x].size(); i++)
        {
            //cout<<v[x][i]<<" ";
            ans.push_back(v[x][i]);
        }
        //cout<<endl;
        sort(ans.begin(), ans.end(),greater<int>());
        if(ans.empty()) cout<<"-1";
        for(int val:ans)
        {
            cout<<val<<" ";
        }
        cout<<endl;
    } 
    return 0;
}