#include <iostream>
#include <vector>
#define int long long
using namespace std;

class SegmentTree
{
private:
    vector<int> tree, lazy;
    int n;

    void build(const vector<int> &arr, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = arr[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void push(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            tree[v] += lazy[v] * (tr - tl + 1);
            if (tl != tr)
            {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void updateRange(int v, int tl, int tr, int l, int r, int addend)
    {
        push(v, tl, tr);
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            lazy[v] += addend;
            push(v, tl, tr);
        }
        else
        {
            int tm = (tl + tr) / 2;
            updateRange(v * 2, tl, tm, l, min(r, tm), addend);
            updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    int getPoint(int v, int tl, int tr, int pos)
    {
        push(v, tl, tr);
        if (tl == tr)
        {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            return getPoint(v * 2, tl, tm, pos);
        }
        else
        {
            return getPoint(v * 2 + 1, tm + 1, tr, pos);
        }
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(n * 4);
        lazy.resize(n * 4, 0);
        build(arr, 1, 0, n - 1);
    }

    void updateRange(int l, int r, int addend)
    {
        updateRange(1, 0, n - 1, l, r, addend);
    }

    int getPoint(int pos)
    {
        return getPoint(1, 0, n - 1, pos);
    }
};

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            st.updateRange(a - 1, b - 1, u); // Converting 1-based index to 0-based
        }
        else if (type == 2)
        {
            int k;
            cin >> k;
            cout << st.getPoint(k - 1) << endl; // Converting 1-based index to 0-based
        }
    }

    return 0;
}
