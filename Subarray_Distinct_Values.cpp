#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mp;
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (j < n)
    {
        mp[arr[j]]++;
        if (mp.size() > k)
        {
            while (i <= j)
            {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(mp.find(arr[i]));
                if (mp.size() == k)
                    break;
                i++;
            }
        }
        if (mp.size() == k)
        {
            int temp = j - i + 1;
            cnt += 1LL * (temp) * (temp - 1) / 2;
            cout << "cnt1 : " << cnt;
            cout<<" i : "<<i<<" j : "<<j<<endl;
        }
        cout << "cnt : " << cnt;
        cout << " i : " << i << " j : " << j << endl;
        j++;
    }
    int temp = j - i + 1;
    cnt += 1LL * (temp) * (temp - 1) / 2;
    cout << cnt << endl;
    return 0;
}