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
    int n, m;
    cin >> n >> m;
    set<int> st;
    vector<int> arr;
    unordered_map<int, int> mp;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        st.insert(temp);
        arr.push_back(temp);
        mp[temp] = i;
    }
    vector<int> v;
    for (auto i : st)
    {
        v.push_back(i);
    }
    int ans = 0;
    int index = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (mp[v[i]] > index)
        {
            index = mp[v[i]];
            continue;
        }
        else
        {
            ans++;
            index = mp[v[i]];
        }
    }
    ans++;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (arr[a] > arr[b])
        {
            if (mp[arr[a]] < mp[arr[b]])
            {
                cout << "hello1" << endl;

                ans--;
                cout << ans << endl;
            }
            else
            {
                cout << "hello2" << endl;

                ans++;
                cout << ans << endl;
            }
            mp[arr[a]] = b;
            mp[arr[b]] = a;
        }
        else
        {
            if (mp[arr[a]] > mp[arr[b]])
            {
                cout << "hello3" << endl;

                ans--;
                cout << ans << endl;
            }
            else
            {
                cout << "hello4" << endl;

                ans++;
                cout << ans << endl;
            }
            mp[arr[a]] = b;
            mp[arr[b]] = a;
        }
    }
    return 0;
}