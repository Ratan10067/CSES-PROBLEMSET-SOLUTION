#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int arr[n];
    map<int, int> index;
    map<int, int> mp;
    int a, b;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(index.find(arr[i])==index.end())
            index[arr[i]] = i;
        if (mp.find(x - arr[i]) != mp.end())
        {
            b = i + 1;
            a = index[x - arr[i]] + 1;
            found = true;
            break;
        }
        mp[arr[i]]++;
    }
    if (!found)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << a << " " << b << endl;
    }
    return 0;
}