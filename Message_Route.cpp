#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 1});
        g[b].push_back({a,1});
    }
    vector<int> dis(n + 1, 1e9);
    dis[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    set<int> par;
    vector<int> vis(n + 1, 0);
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        if (vis[node.S])
            continue;
        vis[node.S] = 1;
        for (auto &v : g[node.S])
        {
            int weigh = v.S;
            if (dis[v.F] > dis[node.S] + weigh)
            {
                dis[v.F] = weigh + dis[node.S];
                par.insert(node.S);
                pq.push({dis[v.S], v.F});
            }
        }
    }
    if (dis[n] == 1e9)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        par.insert(n);
        cout << dis[n] << endl;
        for (auto i : par)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}