#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
class Disjoint
{
public:
    vector<int> par;
    vector<int> size;
    int num_comp = 0;
    Disjoint(int n)
    {
        this->num_comp = n;
        par.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x)
    {
        if (x != par[x])
        {
            return par[x] = find(par[x]);
        }
        return x;
    }

    void merge(int a, int b)
    {
        int parentOfa = find(a);
        int parentOfb = find(b);
        if (parentOfa != parentOfb)
        {
            if (size[parentOfa] >= size[parentOfb])
            {
                par[parentOfb] = parentOfa;
                size[parentOfa] += size[parentOfb];
            }
            else
            {
                par[parentOfa] = parentOfb;
                size[parentOfb] += size[parentOfa];
            }
            num_comp--;
        }
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Disjoint ds(n);
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int findofa = ds.find(a);
        int findofb = ds.find(b);
        if (findofa != findofb)
        {
            ans += v[i].first;
            cnt++;
            ds.merge(a, b);
        }
    }
    if (cnt != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}