#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
signed main()
{
    int n, m;
    cin >> n >> m;
    int num_coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num_coins[i];
    }
    vector<vector<int>> g;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    return 0;
}