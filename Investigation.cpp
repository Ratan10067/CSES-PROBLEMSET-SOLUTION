#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
const int mod = 1e9 + 7;
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
    vector<int> minimum_number_of_flights(n + 1, 1e18); // Initialize with large value
    vector<int> maximum_number_of_flights(n + 1, 0);
    vector<int> num_path(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    num_path[1] = 1;
    dis[1] = 0;
    minimum_number_of_flights[1] = 0; // Starting point has 0 flights
    vector<int> vis(n + 1, 0);
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
                dis[v.F] = dis[node.S] + v.S;
                num_path[v.F] = num_path[node.S] % mod;
                minimum_number_of_flights[v.F] = minimum_number_of_flights[node.S] + 1;
                maximum_number_of_flights[v.F] = maximum_number_of_flights[node.S] + 1;
                pq.push({dis[v.F], v.F});
            }
            else if (dis[v.F] == dis[node.S] + v.S)
            {
                num_path[v.F] = (num_path[v.F] % mod + num_path[node.S] % mod) % mod;
                minimum_number_of_flights[v.F] = min(minimum_number_of_flights[v.F], minimum_number_of_flights[node.S] + 1);
                maximum_number_of_flights[v.F] = max(maximum_number_of_flights[v.F], maximum_number_of_flights[node.S] + 1);
            }
        }
    }
    cout << dis[n] << " " << num_path[n] << " ";
    cout << minimum_number_of_flights[n] << " " << maximum_number_of_flights[n] << endl;
    return 0;
}
