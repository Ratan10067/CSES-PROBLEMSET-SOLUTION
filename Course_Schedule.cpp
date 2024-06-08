#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false)
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g;
    g.resize(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &v : g[node])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}