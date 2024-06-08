#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
bool isCycle = false;
#define MP make_pair
vector<vector<int>> g;
vector<int> parent;
vector<int> col;
vector<int> ans;
int n,m;
void dfs(int node,int par)
{
    col[node] = 2;
    parent[node] = par;
    for(auto &v:g[node])
    {
        if(col[v]==1)
        {
            dfs(v,node);
        }
        else if(col[v]==2)
        {
            if(isCycle)
            {
                int temp = node;
                while (temp != v)
                {
                    ans.push_back(temp);
                    temp = parent[temp];
                }
                ans.push_back(temp);
            }
            isCycle = 1;
        }
    }
    col[node] = 3;
}
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
        g[b].push_back(a);
    }
    parent.resize(n+1);
    col.assign(n+1,1);
    for(int i=1;i<=n;i++)
    {
        if(col[i]==1)
        {
            dfs(i,-1);
        }
    }
    if(isCycle)
    {
        for(auto i:ans)cout<<i<<" ";cout<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}