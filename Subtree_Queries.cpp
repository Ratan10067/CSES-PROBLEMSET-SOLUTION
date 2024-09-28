/*
This question is solved by concept of euler tour and the concept of segment tree, Here Segment tree is used to update the range and answer the query
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5000001;
vector<int> g[MAXN];
int val[MAXN];
int euler[2 * MAXN]; // To map values based on DFS entry times
int timer = 0;
int in[MAXN], out[MAXN]; // DFS entry and exit times
int n;
int tree[4 * 2 * MAXN]; // Segment Tree

// DFS to record the "in" and "out" times for nodes
void dfs(int node, int par)
{
    in[node] = ++timer;
    euler[in[node]] = val[node]; // Map node value to its DFS entry time
    for (auto &v : g[node])
    {
        if (v != par)
        {
            dfs(v, node);
        }
    }
    out[node] = timer; // The exit time is the same as the last node visited in its subtree
}

// Segment Tree build function
void build(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = euler[s]; // Assign value based on DFS order
        return;
    }
    int mid = (s + e) >> 1;
    build(node << 1, s, mid);                           // Build left child
    build(node << 1 | 1, mid + 1, e);                   // Build right child
    tree[node] = tree[node << 1] + tree[node << 1 | 1]; // Merge the two halves
}

// Update function for Segment Tree
void update(int node, int l, int r, int idx, int val)
{
    if (l == r)
    {
        tree[node] = val; // Update the value at position 'idx' with 'val'
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid)
        update(node << 1, l, mid, idx, val); // Update in the left child
    else
        update(node << 1 | 1, mid + 1, r, idx, val);    // Update in the right child
    tree[node] = tree[node << 1] + tree[node << 1 | 1]; // Recalculate the sum
}

// Query function for Segment Tree
int query(int node, int l, int r, int x, int y)
{
    if (l > y || r < x) // Completely outside the range
        return 0;
    if (l >= x && r <= y) // Fully inside the range
        return tree[node];
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, x, y) + query(node << 1 | 1, mid + 1, r, x, y);
}

signed main()
{
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);      // Start DFS from the root (node 1)
    build(1, 1, n); // Build the segment tree using DFS order

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            // Update query
            int s, x;
            cin >> s >> x;
            update(1, 1, n, in[s], x); // Update the value of node 's' at its 'in' time
        }
        else
        {
            // Subtree sum query
            int s;
            cin >> s;
            cout << query(1, 1, n, in[s], out[s]) << endl; // Query the subtree of node 's'
        }
    }
    return 0;
}
