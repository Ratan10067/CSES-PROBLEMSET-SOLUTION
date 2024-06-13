#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

signed main()
{
    IOS;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    map<int, int> mp; // To store the frequency of elements
    int i = 0, j = 0, ans = 0;

    while (j < n)
    {
        mp[v[j]]++;

        // If the current element makes a duplicate in the window
        while (mp[v[j]] > 1)
        {
            mp[v[i]]--;
            i++;
        }

        // Calculate the maximum length of the subarray
        ans = max(ans, j - i + 1);
        j++;
    }

    cout << ans << endl;
    return 0;
}
