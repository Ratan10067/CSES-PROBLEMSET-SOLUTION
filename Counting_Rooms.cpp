#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<string> arr;
using ii = pair<int, int>;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool visited[1000][1000];

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void dfs(ii k)
{
    int x = k.first, y = k.second;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        if (check(x + dx[i], y + dy[i]) && arr[x + dx[i]][y + dy[i]] == '.')
        {
            if (!visited[x + dx[i]][y + dy[i]])
            {
                dfs({x + dx[i], y + dy[i]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    arr.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && arr[i][j] == '.')
            {
                dfs({i, j});
                ans++;
            }
        }
    }
    cout << ans << endl;
}
