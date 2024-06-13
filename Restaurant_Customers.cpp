#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    for (int i = 0; i < v.size(); i++)
    {
        cnt += v[i].second;
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}