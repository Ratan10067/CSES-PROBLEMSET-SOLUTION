#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
signed main()
{
    lli n;
    cin >> n;
    lli arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lli cnt = 0;
    lli sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cnt = 0;
        if (arr[i + 1] < arr[i])
        {
            cnt += abs(-arr[i + 1] + arr[i]);
            sum += cnt;
            arr[i + 1] = cnt + arr[i + 1];
        }
    }
    cout << sum << endl;
    return 0;
}