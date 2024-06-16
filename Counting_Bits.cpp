#include <bits/stdc++.h>
using namespace std;

#define int long long
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
    int count = 0;
    n++;
    for (int x = 2; x / 2 < n; x = x * 2)
    {
        int quotient = n / x;
        count += (quotient) * (x / 2);
        int remainder = n % x;
        if (remainder > x / 2)
        {
            count += (remainder - x / 2);
        }
    }
    cout << count << endl;
    return 0;
}