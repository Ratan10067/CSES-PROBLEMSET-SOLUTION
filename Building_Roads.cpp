#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int n,m;
vector<vector<int>> g;
signed main()
{
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    
    return 0;
}