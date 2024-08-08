#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define F first
#define S second
#define MP make_pair

const int MAXN = 100000;
const int LOG = 32;

int n, q;
vector<int> teleport;    // Stores the destination for each planet
vector<vector<int>> par; // Binary lifting table

void preprocess()
{
    par.assign(n + 1, vector<int>(LOG, -1)); // Initialize binary lifting table

    // Initialize the 0-th ancestor (direct teleportation)
    for (int i = 1; i <= n; i++)
    {
        par[i][0] = teleport[i];
    }

    // Fill the table
    for (int j = 1; j < LOG; j++)
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
    IOS; // Optimize I/O

    cin >> n >> q;
    teleport.resize(n + 1);

    // Read the teleport destinations
    for (int i = 1; i <= n; i++)
    {
        cin >> teleport[i];
    }

    // Preprocess to build the binary lifting table
    preprocess();

    // Process each query
    while (q--)
    {
        int x, k;
        cin >> x >> k;

        // Answer the query using binary lifting
        for (int i = 0; i < LOG; i++)
        { // Iterate from lowest bit to highest
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
