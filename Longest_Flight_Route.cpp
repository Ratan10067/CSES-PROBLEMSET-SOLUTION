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
    vector<vector<pair<int, int>>> g;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 1});
    }
    vector<int> path;
    vector<vector<int>> ans;
    vector<int> num_path(n + 1);
    queue<pair<int, int>> q;
    vector<int> dis(n + 1, 1e9);
    q.push({0, 1});
    num_path[1] = 1;
    dis[1] = 0;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        path.push_back(node.S);
        for (auto &v : g[node.S])
        {
            cout<<"hello "<<v.F<<" "<<v.S<<endl;
            if (dis[v.F] > dis[node.S] + v.S)
            {
                dis[v.F] = dis[node.S] + v.S;
                num_path[v.F] = num_path[node.S];
                path.push_back(v.F);
                if (v.F == n)
                    ans.push_back(path);
                q.push({dis[v.F], v.F});
            }
            else if(dis[v.F]==dis[node.S] + v.S)
            {
                num_path[v.F] += num_path[node.S];
            }
        }
    }
    for (auto i : dis)
        cout << i << " ";
    cout << endl;
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}