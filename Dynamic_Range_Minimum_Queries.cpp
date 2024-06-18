#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> tree;
vector<int> v;
#define INF 1e18
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
void update(int node, int start, int end, int i, int x)
{
    if (start == end)
    {
        v[i] = x;
        tree[node] = x;
        return;
    }
    int mid = start + (end - start) / 2;
    if (i <= mid)
    {
        update(2 * node, start, mid, i, x);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, i, x);
    }
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
    ios_base::sync_with_stdio(false);
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
        int t;
        cin >> t;
        if (t == 1)
        {
            int i, x;
            cin >> i >> x;
            i--;
            update(1, 0, n - 1, i, x);
        }
        else
        {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            cout << query(1, 0, n - 1, i, j) << endl;
        }
    }
    return 0;
}