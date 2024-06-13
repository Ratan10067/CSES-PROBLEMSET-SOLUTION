#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> mt;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        mt.insert(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        auto it = mt.lower_bound(temp);
        if(*it==temp)
        {
            cout<<temp<<endl;
            mt.erase(mt.find(temp));
        }
        else if (it == mt.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            --it;
            int value = *it;
            cout << value << endl;
            mt.erase(mt.find(value));
        }
    }
    return 0;
}