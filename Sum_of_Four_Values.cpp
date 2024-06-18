#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
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

    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Map to store sum of pairs and their indices
    unordered_map<int, pair<int, int>> mp;

    // Loop through all pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int current_sum = v[i] + v[j];
            int required_sum = x - current_sum;
            if (mp.find(required_sum) != mp.end())
            {
                pair<int, int> p = mp[required_sum];
                // Ensure all indices are distinct
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
        // Add pairs to map after the above check to avoid using the same pair
        for (int j = 0; j < i; j++)
        {
            mp[v[i] + v[j]] = {j, i};
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
