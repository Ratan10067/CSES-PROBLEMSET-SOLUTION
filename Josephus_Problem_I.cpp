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
    int n;
    cin >> n;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    list<int> l;
    for (int i = 1; i <= n; i++)
    {
        l.push_back(i);
    }
    auto start = l.begin();
    start++;
    auto end = l.rbegin();
    while (!l.empty())
    {
        if (l.size() == 1)
        {
            cout << *start << " ";
            l.erase(start);
        }
        else
        {
            cout << *start << " ";
            start = l.erase(start);
            if (start == l.end())
            {
                start = l.begin();
            }

            if (start != l.end())
            {
                ++start;
            }
            if (start == l.end())
            {
                start = l.begin();
            }
        }
    }
    cout << endl;
    return 0;
}