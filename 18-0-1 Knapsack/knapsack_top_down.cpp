#include<bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knapsack(int n, int weight[],int value[],int w)
{
    if(n<0 || w==0) return 0;
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if(weight[n]<=w)
    {
        // 2 option, niye & na niye
        int opt1 = knapsack(n-1,weight,value,w-weight[n]) + value[n];
        int opt2 = knapsack(n-1,weight,value,w);
        return dp[n][w] = max(opt1,opt2);
    }
    else
    {
        // 1 option, na niye
        int opt2 = knapsack(n-1,weight,value,w);
        return dp[n][w] = opt2;
    }
    
}
int main()
{
    int n;
    cin>>n;
    int weight[n], value[n];
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }
    int w;
    cin>>w;
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(n-1,weight,value,w);
    return 0;
}