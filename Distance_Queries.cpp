#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

vector<vector<int>> g;
int parent[500000][20];
int depth[500000];
int prefix[500000];

void dfs(int node, int par, int dep)
{
    parent[node][0] = par;
    depth[node] = dep;
    prefix[node] = prefix[par] + 1;
    for (int i = 1; i < 20; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (auto &v : g[node])
    {
        if (v != par)
        {
            dfs(v, node, dep + 1);
        }
    }
}

int get_lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            u = parent[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

signed main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    g.clear();
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix[a] + prefix[b] - 2 * prefix[get_lca(a, b)] << endl;
    }
    return 0;
}
