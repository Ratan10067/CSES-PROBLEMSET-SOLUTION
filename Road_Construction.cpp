#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair

class DisJoint
{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int num_comp;

    DisJoint(int n)
    {
        this->n = n;
        parent.resize(n + 1); // Resize to n+1 to use 1-based indexing
        size.resize(n + 1);
        num_comp = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int x)
    {
        if (parent[x] != x)
            return parent[x] = Find(parent[x]); // Path compression
        return x;
    }

    void merge(int a, int b)
    {
        int parentOfa = Find(a);
        int parentOfb = Find(b);

        if (parentOfa != parentOfb)
        {
            if (size[parentOfa] < size[parentOfb])
            {
                parent[parentOfa] = parentOfb;
                size[parentOfb] += size[parentOfa];
            }
            else
            {
                parent[parentOfb] = parentOfa;
                size[parentOfa] += size[parentOfb];
            }
            num_comp--; // Decrease the number of components
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
    DisJoint ds(n);
    int temp = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ds.merge(a, b);
        int findPara = ds.Find(a);
        int maxSize = ds.size[findPara];
        maxSize = max(temp, maxSize);
        cout << ds.num_comp << " " << maxSize << endl;
        temp = maxSize;
    }

    return 0;
}
