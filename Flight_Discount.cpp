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
    vector<int> par;
    vector<int> dis(n + 1, 1e18);
    vector<int> vis(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        if (vis[node.S])
            continue;
        vis[node.S] = 1;
        for(auto &v:g[node.S])
        {
            if(dis[v.F]>dis[node.S] + v.S)
            {
                dis[v.F] = dis[node.S] + v.S;
                par.push_back(node.S);
                pq.push({dis[v.F],v.F});
            }
        }
    }
    for(auto i:dis)cout<<i<<" ";cout<<endl;
    for(auto i:par)cout<<i<<" ";cout<<endl;
    return 0;
}