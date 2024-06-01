#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    int maximum = INT_MIN;
    sort(v.begin(), v.end());
    if ((int)v.size() & 1)
    {
        maximum = v[v.size() / 2];
        for (int i = 0; i < n; i++)
        {
            ans += abs(maximum - v[i]);
        }
    }
    else
    {
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        maxi1 = v[v.size() / 2];
        maxi2 = v[v.size() / 2 - 1];
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            ans1 += abs(maxi1 - v[i]);
        }
        for (int i = 0; i < n; i++)
        {
            ans2 += abs(maxi2 - v[i]);
        }
        ans = min(ans1, ans2);
    }
    cout << ans << endl;
    return 0;
}