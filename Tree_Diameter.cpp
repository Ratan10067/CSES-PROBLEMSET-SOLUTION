#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
vector<vector<int>> g;
vector<int> dis;
int n;
void dfs(int node, int depth, int parent)
{
    dis[node] = depth;
    for (auto &v : g[node])
    {
        if (v != parent)
        {
            dfs(v, depth + 1, node);
        }
    }
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dis.assign(n + 1, 0);
    int maxi = 0;
    dfs(1, 0, 0);
    int maxDepth = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxDepth)
        {
            maxi = i;
            maxDepth = dis[i];
        }
    }
    dfs(maxi, 0, 0);
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
    return 0;
}