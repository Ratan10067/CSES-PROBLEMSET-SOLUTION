#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int n;
vector<vector<int>> g;
int subTreeSize[500000];
void dfs(int node, int parent)
{
    subTreeSize[node] = 1;
    for (auto &v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node);
            subTreeSize[node] += subTreeSize[v];
        }
    }
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int temp;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        g[i + 2].push_back(temp);
        g[temp].push_back(i + 2);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << subTreeSize[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}