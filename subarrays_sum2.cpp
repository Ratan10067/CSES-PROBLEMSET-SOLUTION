#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pi 3.14

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n); // Use vector instead of array for dynamic allocation

    // Read input and calculate prefix sums
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        {
            arr[i] += arr[i - 1];
        }
    }

    int sum = 0;
    unordered_map<int, int> mp;
    mp[0]++; // To handle cases where the subarray starts from index 0

    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i] - x) != mp.end())
        {
            sum += mp[arr[i] - x];
        }
        mp[arr[i]]++;
    }

    cout << sum << endl;
    return 0;
}
