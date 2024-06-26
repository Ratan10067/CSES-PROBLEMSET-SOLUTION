#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
vector<pair<int, int>> v;
int tower_of_hanoi(int x, int source, int target, int middle)
{
    if (x == 0)
    {
        return 0;
    }
    int sum1 = tower_of_hanoi(x - 1, source, middle, target);
    v.push_back({source, target});
    int sum2 = tower_of_hanoi(x - 1, middle, target, source);
    return sum1 + sum2 + 1;
}
signed main()
{
    int n;
    cin >> n;
    cout << tower_of_hanoi(n, 1, 3, 2) << endl;
    for (auto i : v)
        cout << i.first << " " << i.second << endl;
    return 0;
}