#include <bits/stdc++.h>
using namespace std;
#define int long long

// Function to precompute the number of divisors for each number up to maxN
vector<int> precompute_divisors(int maxN)
{
    vector<int> divisors(maxN + 1, 0);

    for (int i = 1; i <= maxN; ++i)
    {
        for (int j = i; j <= maxN; j += i)
        {
            divisors[j]++;
        }
    }
    return divisors;
}

signed main()
{
    ios_base::sync_with_stdio(false); // Fast IO
    cin.tie(0);                       // Untie cin from cout
    cout.tie(0);                      // Untie cout from cin

    int t;
    cin >> t; // Number of test cases

    vector<int> queries(t);
    int maxN = 0;

    // Read all queries and find the maximum value among them
    for (int i = 0; i < t; ++i)
    {
        cin >> queries[i];
        if (queries[i] > maxN)
        {
            maxN = queries[i];
        }
    }
    // Precompute the number of divisors for all numbers up to maxN
    vector<int> divisors = precompute_divisors(maxN);

    // Answer each query
    for (int i = 0; i < t; ++i)
    {
        cout << divisors[queries[i]] << endl;
    }

    return 0;
}
