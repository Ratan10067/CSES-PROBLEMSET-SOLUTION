#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    int temp;
    multiset<int> mt;
    for (int i = 0; i < n; i++)
    {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        mt.insert(temp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int min_value = applicants[i] - k;
        int max_value = applicants[i] + k;
        if (!mt.empty())
        {
            auto min_it = mt.lower_bound(min_value);
            if (min_it != mt.end() && *min_it <= max_value)
            {
                ans++;
                mt.erase(min_it);
            }
        }
    }
    cout << ans << endl;
    return 0;
}