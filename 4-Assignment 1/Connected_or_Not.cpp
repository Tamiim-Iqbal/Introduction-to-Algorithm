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
    }
    int q;
    cin>>q;
    while(q--)
    {
        bool flag = false;
        int x,des;
        cin>>x>>des;

        if(x==des)
        {
            flag = true;
        }

        else
        {
            for(int i=0; i<v[x].size(); i++)
            {
                if(v[x][i]==des)
                {
                    flag = true;
                    break;
                }
                
            }
        }
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
    return 0;
}
