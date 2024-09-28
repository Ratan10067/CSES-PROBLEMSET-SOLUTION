// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// // Function to precompute the number of divisors for each number up to maxN
// vector<int> precompute_divisors(int maxN)
// {
//     vector<int> divisors(maxN + 1, 0);

//     for (int i = 1; i <= maxN; ++i)
//     {
//         for (int j = i; j <= maxN; j += i)
//         {
//             divisors[j]++;
//         }
//     }
//     return divisors;
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false); // Fast IO
//     cin.tie(0);                       // Untie cin from cout
//     cout.tie(0);                      // Untie cout from cin

//     int t;
//     cin >> t; // Number of test cases

//     vector<int> queries(t);
//     int maxN = 0;

//     // Read all queries and find the maximum value among them
//     for (int i = 0; i < t; ++i)
//     {
//         cin >> queries[i];
//         if (queries[i] > maxN)
//         {
//             maxN = queries[i];
//         }
//     }
//     // Precompute the number of divisors for all numbers up to maxN
//     vector<int> divisors = precompute_divisors(maxN);

//     // Answer each query
//     for (int i = 0; i < t; ++i)
//     {
//         cout << divisors[queries[i]] << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
#define MAXN 1000000
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> v(MAXN + 1);
    for (int i = 0; i <= MAXN; i++)
    {
        v[i] = i;
    }

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (v[i] == i)
        {
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                if (v[j] == j)
                {
                    v[j] = i;
                }
            }
        }
    }

    while (t--)
    {
        int x;
        cin >> x;
        map<int, int> mp;
        while (x > 1)
        {
            mp[v[x]]++;
            x /= v[x];
        }
        int ans = 1;
        for (auto &i : mp)
        {
            ans *= (i.second + 1);
        }
        cout << ans << endl;
    }
    return 0;
}