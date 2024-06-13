#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &component)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component.push_back(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj_list[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
                component.push_back(neighbor);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            vector<int> component;
            bfs(i, adj_list, visited, component);
            components.push_back(component);
        }
    }

    int num_components = components.size();
    if (num_components == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << num_components - 1 << endl;
        for (int i = 1; i < num_components; ++i)
        {
            cout << components[i - 1][0] << " " << components[i][0] << endl;
        }
    }

    return 0;
}
