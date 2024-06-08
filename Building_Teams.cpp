#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false);
#define F first
#define S second
#define MP make_pair
vector<vector<int>> g;
int n, m;
vector<int> ans;
bool is_bipartite = true;
void dfs(int node, int col)
{
    ans[node] = col;
    for (auto &v : g[node])
    {
        if (ans[v] == 0)
        {
            dfs(v, 3 ^ col);
        }
        else if (ans[node] == ans[v])
        {
            is_bipartite = false;
        }
    }
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            dfs(i, 1);
    }
    if (!is_bipartite)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}