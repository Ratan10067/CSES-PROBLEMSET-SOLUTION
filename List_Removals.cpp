#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
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
    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    int n;
    cin >> n;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        l.push_back(temp);
        mp.insert({i, {temp, l.begin()}});
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int position;
        cin >> position;
        auto it = mp.find(position);
        if (it != mp.end())
        {
            list<int>::iterator t = it->second.second;
            ans.push_back(*t);
            l.erase(t);
            mp.erase(mp.find(i));
        }
    }
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}