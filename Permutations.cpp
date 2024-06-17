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
    if (n == 3 or n == 2)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    if (n == 1)
    {
        cout << n << endl;
        return 0;
    }
    if (n == 4)
    {
        cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
        return 0;
    }
    vector<int> ans;
    int i = 1;
    while (i <= n)
    {
        ans.push_back(i);
        i += 2;
    }
    i = 2;
    while (i <= n)
    {
        ans.push_back(i);
        i += 2;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}