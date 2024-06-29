#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;

bool dfs(int v, int par, stack<int> &path)
{
    visited[v] = true;
    path.push(v);

    for (int u : adj[v])
    {
        if (!visited[u])
        {
            parent[u] = v;
            if (dfs(u, v, path))
            {
                return true;
            }
        }
        else if (u != par)
        {
            path.push(u);
            return true;
        }
    }
    path.pop();
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> path;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i] && dfs(i, -1, path))
        {
            vector<int> cycle;
            int start = path.top();
            path.pop();
            cycle.push_back(start);
            while (!path.empty() && path.top() != start)
            {
                cycle.push_back(path.top());
                path.pop();
            }
            cycle.push_back(start);

            cout << cycle.size() << endl;
            for (int city : cycle)
            {
                cout << city << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
