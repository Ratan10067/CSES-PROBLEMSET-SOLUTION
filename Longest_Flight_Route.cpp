#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

vector<vector<int>> g;
vector<int> depth;
vector<int> parent;
vector<int> indegree;
int n, m;
void topological_sort(int n, vector<int> &order)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (auto v : g[node])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

signed main()
{
    IOS;
    cin >> n >> m;
    g.resize(n + 1);
    depth.assign(n + 1, LLONG_MIN);
    parent.assign(n + 1, -1);
    indegree.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indegree[b]++;
    }

    vector<int> order;
    topological_sort(n, order);
    
    depth[1] = 0; // Start from node 1

    for (auto node : order)
    {
        if (depth[node] != LLONG_MIN)
        {
            for (auto v : g[node])
            {
                if (depth[v] < depth[node] + 1)
                {
                    depth[v] = depth[node] + 1;
                    parent[v] = node;
                }
            }
        }
    }

    if (depth[n] == LLONG_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << depth[n] + 1 << endl;
    vector<int> ans;
    for (int temp = n; temp != -1; temp = parent[temp])
    {
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    for (int node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
