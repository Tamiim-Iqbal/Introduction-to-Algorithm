#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset(int a[],int n, int s)
{
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }
    if(dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (a[n-1] <= s)
    {
        int op1 = subset(a,n-1,s-a[n-1]);
        int op2 = subset(a,n-1,s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        int op2 = subset(a,n-1,s);
        return dp[n][s] = op2;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    if(subset(a,n,s))
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}