#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
int rec(int n, int a = 2)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = ((((ans % mod) * a) % mod) % mod);
            n = n - 1;
        }
        else
        {
            a = (((a % mod) * a) % mod);
            n /= 2;
        }
    }
    return ans;
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}