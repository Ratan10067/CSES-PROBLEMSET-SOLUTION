#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
void rec(int level,vector<int> v,int *dp,const int n,int sum)
{
    if(level == n+1)return;
    if(level==n)
    {
        cout<<"hello "<<sum<<endl;
        dp[level] = sum;
        return;
    }
    if(dp[level]!=-1)return;
    rec(level + 1, v, dp, n, sum);
    rec(level+1,v,dp,n,sum+v[level]);
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int dp[100100];
    memset(dp,-1,sizeof(dp));
    int sum = 0;
    rec(0,v,dp,n,sum);
    for (int i = 0; i < 20; i++)
    {
        cout<<dp[i]<<" ";
    }
    return 0;
}