#include <bits/stdc++.h>
using namespace std;
int ans[500100];
int indp[500100];
int outdp[500100];
vector<int> g[500100];
int n;
void dfsin(int node, int par)
{
    indp[node] = 0;
    for (auto i : g[node])
    {
        if (i != par)
        {
            dfsin(i, node);
            indp[node] = max(indp[node], indp[i] + 1);
        }
    }
}

void dfsout(int node, int par, int outval)
{
    outdp[node] = outval;
    int max1 = -1, max2 = -1;
    for (auto i : g[node])
    {
        if (i != par)
        {
            if (indp[i] > max1)
            {
                max2 = max1;
                max1 = indp[i];
            }
            else if (indp[i] > max2)
            {
                max2 = indp[i];
            }
        }
    }

    for (auto i : g[node])
    {
        if (i != par)
        {
            if (indp[i] == max1)
            {
                dfsout(i, node, max(max2 + 2, outdp[node] + 1));
            }
            else
            {
                dfsout(i, node, max(max1 + 2, outdp[node] + 1));
            }
        }
    }
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfsin(1, 0);
    dfsout(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = max(indp[i], outdp[i]);
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}