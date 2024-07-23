#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> tree;
vector<int> v;
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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node, int start, int end, int i, int x, int u)
{
    if (start == end)
    {
        v[i] = +x;
        tree[node] = v[i];
        return;
    }
    int mid = start + (end - start) / 2;
    if (i <= mid)
    {
        update(2 * node, start, mid, i, x,u);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, i, x,u);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    tree.resize(4 * n);
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
            int i, x, u;
            cin >> i >> x >> u;
            i--;
            update(1, 0, n - 1, i, x,u);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << v[k] << endl;
        }
    }
    return 0;
}