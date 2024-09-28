#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100001];
vector<int> grev[100001];
vector<int> vis(100001, 0);
vector<int> tout_order;
vector<vector<int>> codensed_graph;
void dfs1(int node)
{
    vis[node] = 1;
    for (auto &v : g[node])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    tout_order.push_back(node);
}
int curr_scc = 0;
int src_num[100001];
void dfs2(int node)
{
    src_num[node] = curr_scc;
    vis[node] = 1;
    for (auto &v : grev[node])
    {
        if (!vis[v])
        {
            dfs2(v);
        }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        grev[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    reverse(tout_order.begin(), tout_order.end());
    vis.assign(n + 1, 0);
    for (auto x : tout_order)
    {
        if (!vis[x])
        {
            curr_scc++;
            dfs2(x);
        }
    }
    if (curr_scc == 1)
    {
        cout << "YES" << endl;
        return 0;
    }
    codensed_graph.resize(curr_scc + 1);
    int indeg[100001] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (auto v : g[i])
        {
            if (src_num[i] != src_num[v])
            {
                cout << i << " " << v << endl;
                return 0;
            }
        }
    }
    return 0;
}
