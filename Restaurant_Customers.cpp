#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for(auto i:v)cout<<i.first<<" "<<i.second<<endl;
    for (int i = 0; i < n; i++)
    {
        cnt += v[i].second;
        if (i + 1 < n and cnt > 0)
        {
            ans = max(ans, v[i + 1].first - v[i].first);
        }
    }
    cout << ans << endl;
    return 0;
}