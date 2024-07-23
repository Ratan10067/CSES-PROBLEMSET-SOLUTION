#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)

vector<vector<int>> g;
int par[500000][32];
// Binary Lifting Code Start
void dfs(int node, int parent)
{
    par[node][0] = parent;
    for (int i = 1; i <= 31; i++)
    {
        if (par[node][i - 1] != -1)
        {
            par[node][i] = par[par[node][i - 1]][i - 1];
        }
        else
        {
            par[node][i] = -1;
        }
    }
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node);
        }
    }
}
// Binary Lifting Code Ends
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    memset(par, -1, sizeof(par));
    dfs(1, -1);
    while (q--)
    {
        int a;
        int b;
        cin >> a >> b;
        for (int i = 0; i <= 31; i++)
        {
            if (b & (1 << i))
            {
                a = par[a][i];
                if (a == -1)
                    break;
            }
        }
        cout << a << endl;
    }
    return 0;
}