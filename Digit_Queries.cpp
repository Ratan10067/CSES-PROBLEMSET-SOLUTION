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
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int temp = k;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp /= 10;
        }
        cnt--;
        if (cnt != 0)
        {
            int val = 10 * cnt;
            int var = k%10;
            cout << val + var << endl;
        }
        else
        {
            cout << k << endl;
        }
    }
    return 0;
}