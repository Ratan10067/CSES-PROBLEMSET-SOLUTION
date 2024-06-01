#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
signed main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0;
    int j = 0;
    int cnt = 0;
    int sum = 0;
    while (j < n)
    {
        cnt += arr[j];
        if (cnt >= x)
        {
            while (i <= j)
            {
                if (cnt == x)
                {
                    sum++;
                    break;
                }
                if (cnt < x)
                    break;
                cnt -= arr[i];
                i++;
            }
        }
        j++;
    }
    cout << sum << endl;
    return 0;
}
