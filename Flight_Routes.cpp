#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
const int INF = 1e9;
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vector<int> ans;
    vector<int> dis(n + 1, INF);
    map<int, vector<int>> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        pair<int, int> frontNode = pq.top();
        pq.pop();
        for (auto &v : g[frontNode.S])
        {
            if (dis[v.F] > dis[frontNode.S] + v.S)
            {
                dis[v.F] = dis[frontNode.S] + v.S;
                mp[v.F].push_back(dis[v.F]);
                if (v.F == n)
                {
                    ans.push_back(dis[v.F]);
                }
                pq.push({dis[v.F], v.F});
            }
            else if (v.F == n)
            {
                ans.push_back(dis[v.F]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}