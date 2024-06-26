#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
#define INF 1e9
vector<vector<int>> g;
vector<int> par;
vector<int> dis;
int n, m;
vector<int> ans;
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    dis[node] = 1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto &v : g[frontNode])
        {
            if (dis[v] == INF)
            {
                dis[v] = dis[frontNode] + 1;
                par[v] = frontNode;
                q.push(v);
            }
        }
        if (dis[n] != INF)
        {
            int temp = n;
            while (temp != 1)
            {
                ans.push_back(temp);
                temp = par[temp];
            }
            ans.push_back(1);
            return;
        }
    }
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dis.assign(n + 1, INF);
    par.resize(n + 1);
    bfs(1);
    reverse(ans.begin(), ans.end());
    if (dis[n] == INF)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << dis[n] << endl;
        for (auto &v : ans)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}