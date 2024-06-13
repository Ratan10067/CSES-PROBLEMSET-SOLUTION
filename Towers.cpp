#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long

signed main()
{
    int n;
        cin >> n;
        multiset<int> s;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            auto it = s.upper_bound(x);
            if (it == s.end())
            {
                s.insert(x);
            }
            else
            {
                s.erase(it);
                s.insert(x);
            }
        }
        cout << s.size() << "\n";
    return 0;
}
