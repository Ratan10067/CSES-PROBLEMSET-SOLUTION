#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
int binPow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (((res % mod) * a) % mod + mod) % mod;
            b = b - 1;
        }
        else
        {
            a = (a * a) % mod;
            b = b >> 1;
        }
    }
    return res;
}
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << (binPow(a, b) + mod) % mod << endl;
    }
    return 0;
}