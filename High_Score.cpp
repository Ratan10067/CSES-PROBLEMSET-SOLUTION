#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.push_back({a, b, -c});
    }
    vector<int> dis(n + 1, 1e18);
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &it : g)
        {
            auto u = it[0];
            auto v = it[1];
            auto w = it[2];
            if (dis[u] != 1e18 and (dis[u] + w < dis[v]))
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    bool found = 0;
    for (auto &it : g)
    {
        auto u = it[0];
        auto v = it[1];
        auto w = it[2];
        if (dis[u] != 1e18 and (dis[u] + w < dis[v]))
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        cout << -1 << endl;
    }
    else if (dis[n] == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dis[n] * -1 << endl;
    }
    return 0;
}