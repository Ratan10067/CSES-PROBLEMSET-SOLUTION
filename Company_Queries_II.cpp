#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
int par[500000][32];
int depth[500000];
vector<vector<int>> g;
int n, q;
// Binary Lifting code Start
void dfs(int node, int parent, int dep)
{
    par[node][0] = parent;
    depth[node] = dep;
    for (int i = 1; i < 32; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto &v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, dep + 1);
        }
    }
}
// Binary Lifting code Ends
int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = 31; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 31; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    dfs(1, -1, 0);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}