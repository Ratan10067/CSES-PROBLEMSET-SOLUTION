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
    unordered_map<int, list<int>::iterator> mp;
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        l.push_back(temp);
        mp.insert({i, l.begin()});
    }
    for (int i = 0; i < n; i++)
    {
        int position;
        cin >> position;
        auto it = mp.find(position);
        // cout <<
    }

    return 0;
}