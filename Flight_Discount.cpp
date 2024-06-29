#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
const int INF = 1e18;

signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    vector<vector<int>> dis(n + 1, vector<int>(2, INF));
    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;

    dis[1][0] = 0;
    pq.push({0, 1, false}); // {cost, node, usedCoupon}

    while (!pq.empty())
    {
        auto [current_cost, u, used_coupon] = pq.top();
        pq.pop();

        if (current_cost > dis[u][used_coupon])
            continue;

        for (auto &[v, c] : g[u])
        {
            // Case 1: Not using coupon
            if (current_cost + c < dis[v][used_coupon])
            {
                dis[v][used_coupon] = current_cost + c;
                pq.push({dis[v][used_coupon], v, used_coupon});
            }
            
            // Case 2: Using coupon
            if (!used_coupon && current_cost + c / 2 < dis[v][1])
            {
                dis[v][1] = current_cost + c / 2;
                pq.push({dis[v][1], v, true});
            }
        }
    }

    cout << min(dis[n][0], dis[n][1]) << endl;

    return 0;
}
