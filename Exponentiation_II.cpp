#include <iostream>
using namespace std;

#define int long long
const int MOD = 1000000007;

int binPow(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int b_Power_c = binPow(b, c);
        int ans = binPow(a, b_Power_c);
        cout << ans << endl;
    }
    return 0;
}
