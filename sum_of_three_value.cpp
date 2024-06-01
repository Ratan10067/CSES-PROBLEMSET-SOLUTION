#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pi 3.14
#define int long long
signed main()
{
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    int arr[n];
    multimap<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp.insert({arr[i], i});
    }
    sort(arr, arr + n);
    int i = 0;
    int j = 1;
    int k = n - 1;
    while (i < j and j < k)
    {
        int val = 1LL * arr[i] + 1LL * arr[j] + 1LL * arr[k];
        if (val > x)
        {
            k--;
            if (j < k)
                val = 1LL * arr[i] + 1LL * arr[j] + 1LL * arr[k];
        }
        else if (val < x)
        {
            j++;
            if (j < k)
                val = 1LL * arr[i] + 1LL * arr[j] + 1LL * arr[k];
        }
        if (val == x)
        {
            vector<int> temp;
            auto it1 = mp.find(arr[i]);
            temp.push_back(it1->second);
            mp.erase(it1);
            auto it2 = mp.find(arr[j]);
            temp.push_back(it2->second);
            mp.erase(it2);
            auto it3 = mp.find(arr[k]);
            temp.push_back(it3->second);
            sort(temp.begin(), temp.end());
            cout << temp[2] + 1 << " " << temp[1] + 1 << " " << temp[0] + 1 << endl;
            return 0;
        }
        if (j >= k - 1)
        {
            i++;
            j = i + 1;
            k = n - 1;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}