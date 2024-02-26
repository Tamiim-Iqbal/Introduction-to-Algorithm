#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5;
int dp[N];
int fibo(int n)
{
    if(n==0 || n==1) return n;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    ll ans = fibo(n-1)+fibo(n-2);
    dp[n] = ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<fibo(n)<<endl;
    return 0;
}