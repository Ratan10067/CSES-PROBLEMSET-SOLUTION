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
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int l = v[i].first;
        int r = v[i].second;
        int l_1 = v[i-1].first;
        int r_1 = v[i-1].second;
        if(l>=l_1 and l<=r_1)
        {
            ans++;
        }
    }
    return 0;
}