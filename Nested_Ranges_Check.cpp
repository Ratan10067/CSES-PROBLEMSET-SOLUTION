#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
signed main()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin>>l>>r;
        v.push_back({{l,r},0});
    }
    return 0;
}