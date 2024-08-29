#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

int n, q;
vector<int> teleport;
vector<vector<int>> par;

int computeLog(int x)
{
    return 64 - __builtin_clzll(x) - 1;
}

void preprocess()
{
    int maxLog = computeLog(n) + 1; // Adjust LOG dynamically based on n
    par.assign(n + 1, vector<int>(maxLog, -1));

    for (int i = 1; i <= n; i++)
    {
        par[i][0] = teleport[i];
    }

    for (int j = 1; j < maxLog; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (par[i][j - 1] != -1)
            {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
}

signed main()
{
    IOS;

    cin >> n >> q;
    teleport.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> teleport[i];
    }

    preprocess();

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int maxLog = computeLog(k) + 1;

        for (int i = 0; i < maxLog; i++)
        {
            if (k & (1LL << i))
            {
                x = par[x][i];
                if (x == -1)
                    break;
            }
        }
        cout << x << "\n";
    }

    return 0;
}
