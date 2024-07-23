#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
bool isPossible(vector<int> v, int k)
{
    unordered_map<int, int> mp;
    mp[0]++;
    for (int i = 0; i < v.size(); i++)
    {
        if (mp.find(v[i] - k) != mp.end())
            return 1;
        mp[v[i]]++;
    }
    return 0;
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            v[i] += v[i - 1];
    }
    for(int i=1;i<=sum;i++)
    {
        if(!isPossible(v,i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}