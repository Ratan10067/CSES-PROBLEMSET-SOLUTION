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
    vector<vector<pair<int, int>>> g;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    vector<int> dis(n + 1, -1e18);
    dis[1] = 0;
    // vector<int> vis(n + 1, 0);
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        // if (vis[node.S])
        //     continue;
        // vis[node.S] = 1;
        for (auto &v : g[node.S])
        {
            if (dis[v.F] < dis[node.S] + v.S)
            {
                dis[v.F] = dis[node.S] + v.S;
                pq.push({dis[v.F], v.F});
            }
        }
    }
    if (dis[n] >= 1e9)
        cout << -1 << endl;
    else
        cout << dis[n] << endl;
    return 0;
}