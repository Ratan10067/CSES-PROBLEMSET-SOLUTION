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
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                sum = (sum + i) % mod;
            }
            else
            {
                sum = (sum + i + (n / i)) % mod;
            }
        }
    }
    cout << (sum + mod) % mod << endl;
    return 0;
}