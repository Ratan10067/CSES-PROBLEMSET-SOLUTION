#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
#define INF 1e18
vector<int> v;
vector<int> tree;
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = v[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int start, int end, int l, int r)
{
    if (start >= l and end <= r)
    {
        return tree[node];
    }
    if (start > r or end < l)
    {
        return INF;
    }
    int mid = start + (end - start) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    tree.resize(4 * n, INF);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(1, 0, n - 1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << query(1, 0, n - 1, a, b) << endl;
    }
    return 0;
}