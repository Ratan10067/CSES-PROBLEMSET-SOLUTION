#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort movies by their ending times
    sort(movies.begin(), movies.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int count = 0;
    int last_end_time = 0;

    // Select the maximum number of non-overlapping movies
    for (const auto &movie : movies)
    {
        if (movie.first >= last_end_time)
        {
            ++count;
            last_end_time = movie.second;
        }
    }
    cout << count << endl;
    return 0;
}
