#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false)
int n, m;
vector<vector<int>> g;
vector<vector<int>> grev;
vector<int> vis;
vector<int> topo;
int cnt = 0;
int src_num[200000];

void dfs(int node)
{
    vis[node] = 1;
    for (auto &v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    topo.push_back(node);
}

void dfs1(int node)
{
    src_num[node] = cnt;
    vis[node] = 1;
    for (auto &v : grev[node])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
}

signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    g.resize(n + 1);
    grev.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        grev[b].push_back(a); // Add reverse edge for transpose graph
    }

    vis.resize(n + 1, 0);

    // First DFS to find the topological order
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0); // Reset visited array

    // Second DFS based on reversed topological order
    for (auto i : topo)
    {
        if (!vis[i])
        {
            cnt++;
            dfs1(i);
        }
    }

    cout << cnt << endl; // Number of strongly connected components

    for (int i = 1; i <= n; i++)
    {
        cout << src_num[i] << " ";
    }
    cout << endl;

    return 0;
}
