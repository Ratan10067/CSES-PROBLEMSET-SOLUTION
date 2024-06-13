#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MOD = 1e9 + 7;

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<long long> dp(n + 1, 0);

    // Reading the teleporters and building the graph
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    // Topological sorting using Kahn's Algorithm
    queue<int> q;

    // Initialize the queue with nodes that have zero in-degree
    for (int i = 1; i <= n; ++i)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    dp[1] = 1; // There's exactly one way to start at level 1

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            dp[v] = (dp[v] + dp[u]) % MOD;
            in_degree[v]--;
            if (in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // The result is the number of ways to reach level n
    cout << dp[n] % MOD << endl;

    return 0;
}
