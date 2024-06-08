#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 1e18));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int sum = g[i][k] + g[k][j];
                g[i][j] = min(g[i][j], sum);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << endl;
        else if (g[a][b] == 1e18)
        {
            cout << -1 << endl;
        }
        else
            cout << g[a][b] << endl;
    }
    return 0;
}