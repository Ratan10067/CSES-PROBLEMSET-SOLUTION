#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false) // Fast I/O
#define pi 3.14
#define F first
#define S second
#define MP make_pair

signed main()
{
    IOS;         // Enables fast I/O
    cin.tie(0);  // Disables the synchronization between C and C++ standard streams
    cout.tie(0); // Ensures cout doesn't need to flush the output buffer after every output operation

    int n;    // Number of tasks
    cin >> n; // Read the number of tasks

    vector<pair<int, int>> v; // Vector to store pairs of (duration, deadline) for each task

    for (int i = 0; i < n; i++)
    {
        int a, d;            // a = duration of the task, d = deadline of the task
        cin >> a >> d;       // Read duration and deadline
        v.push_back({a, d}); // Store the pair in the vector
    }

    // Sort the tasks based on their duration (ascending order)
    sort(v.begin(), v.end());

    int startTime = 0; // Variable to keep track of the current start time
    int reward = 0;    // Variable to keep track of the total reward

    for (int i = 0; i < n; i++)
    {
        startTime += v[i].first;             // Increment startTime by the duration of the current task
        reward += (v[i].second - startTime); // Calculate reward for the current task and add to total reward
    }

    cout << reward << endl; // Output the total reward

    return 0;
}
