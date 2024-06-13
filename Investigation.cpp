#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    vector<int> dis(n + 1, 1e18);
    int minimum_number_of_flights = INT_MAX;
    vector<int> num_path(n + 1, 0);
    int maximum_number_of_flights = INT_MIN;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    num_path[1] = 1;
    dis[1] = 0;
    vector<int> vis(n + 1, 0);
    int cnt = 1;
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        if (vis[node.S])
            continue;
        vis[node.S] = 1;
        for (auto &v : g[node.S])
        {
            if (dis[v.F] > dis[node.S] + v.S)
            {
                if (v.F == n)
                {
                    cout<<"hello"<<endl;
                    minimum_number_of_flights = min(minimum_number_of_flights, cnt);
                    maximum_number_of_flights = max(maximum_number_of_flights, cnt);
                }
                cnt++;
                dis[v.F] = dis[node.S] + v.S;
                pq.push({dis[v.F], v.F});
                num_path[v.F] = num_path[node.S];
            }
            else if (dis[v.F] == dis[node.S] + v.S)
            {
                num_path[v.F] = (num_path[v.F] + num_path[node.S]) % mod;
                cnt++;
                if (v.F == n)
                {
                    minimum_number_of_flights = min(minimum_number_of_flights, cnt);
                    maximum_number_of_flights = max(maximum_number_of_flights, cnt);
                }
            }
        }
    }
    for(auto i:dis)cout<<i<<" ";cout<<endl;
    for(auto i:num_path)cout<<i<<" ";cout<<endl;
    cout<<minimum_number_of_flights<<" "<<maximum_number_of_flights<<endl;
    return 0;
}