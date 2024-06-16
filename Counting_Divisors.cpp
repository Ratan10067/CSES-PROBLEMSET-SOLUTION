#include <bits/stdc++.h>
using namespace std;
#define int long long
// Function to count the number of divisors of a number n
int NumberOfDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt += 2; // i and n/i are both divisors
            if (i * i == n)
            {
                cnt--; // If i and n/i are the same, count only once
            }
        }
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false); // Fast IO
    cin.tie(0);                       // Untie cin from cout
    cout.tie(0);                      // Untie cout from cin

    int n;
    cin >> n; // Number of test cases

    while (n--)
    {
        int x;
        cin >> x;                            // Input number
        cout << NumberOfDivisors(x) << endl; // Output number of divisors
    }

    return 0;
}
