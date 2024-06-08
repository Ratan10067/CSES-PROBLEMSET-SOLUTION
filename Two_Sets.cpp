#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
signed main() 
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    if (n % 4 == 1 or n % 4 == 2)
        cout << "NO" << endl;
    else if (n % 4 == 0)
    {
        for (int i = 1; i <= n; i += 4)
        {
            v1.push_back(i + 1);
            v1.push_back(i + 2);
            v2.push_back(i);
            v2.push_back(i + 3);
        }
        cout << "YES" << endl;
        cout << v1.size() << endl;
        for (auto &i : v1)
            cout << i << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (auto &i : v2)
            cout << i << " ";
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i += 4)
        {
            v1.push_back(i + 1);
            v1.push_back(i + 2);
            v2.push_back(i);
            v2.push_back(i + 3);
        }
        v2.erase(v2.begin(), v2.begin() + 1);
        cout << "YES" << endl;
        cout << v1.size() << endl;
        for (auto &i : v1)
            cout << i << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (auto &i : v2)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}