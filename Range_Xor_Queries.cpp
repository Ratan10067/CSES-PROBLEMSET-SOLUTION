#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] = v[i] ^ v[i - 1];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == 0)
        {
            cout << v[b] << endl;
        }
        else
        {
            cout << (v[b] ^ v[a - 1]) << endl;
        }
    }
    return 0;
}