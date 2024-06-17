#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v;
    vector<int> v1(n,0);
    vector<int> v2(n,0);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[i].F.F >= v[i - 1].F.F and v[i].F.S <= v[i - 1].F.S)
        {
            v[i].F.F = min(v[i].F.F, v[i - 1].F.F);
            v[i].F.S = max(v[i].F.S, v[i - 1].F.S);
            v1[v[i - 1].S] = 1;
            v2[v[i].S] = 1;
            v[i].S = v[i - 1].S;
        }
    }
    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    return 0;
}