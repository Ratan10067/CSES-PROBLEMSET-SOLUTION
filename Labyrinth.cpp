#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false)
#define F first
#define S second
#define MP make_pair
using state = pair<int, int>;
int n, m;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
vector<vector<char>> g;
vector<vector<int>> dis;
vector<vector<state>> par;
void bfs(state sc_node, state en_node)
{
    dis[sc_node.F][sc_node.S] = 0;
    par.assign(n, vector<state>(m, {-1, -1}));
    par[sc_node.F][sc_node.S] = {-1, -1};
    queue<state> q;
    q.push(sc_node);
    while (!q.empty())
    {
        state node = q.front();
        q.pop();
        vector<state> temp;
        for (int i = 0; i < 4; i++)
        {
            int x = node.F + dx[i];
            int y = node.S + dy[i];
            if (x >= 0 and x < n and y >= 0 and y < m and g[x][y] != '#')
            {
                temp.push_back({x, y});
            }
        }
        for (auto &v : temp)
        {
            if (dis[v.F][v.S] == -1)
            {
                dis[v.F][v.S] = dis[node.F][node.S] + 1;
                par[v.F][v.S] = node;
                if (dis[en_node.F][en_node.S] != -1)
                    return;
                q.push(v);
            }
        }
    }
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.clear();
    g.resize(n);
    state s, e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            g[i].push_back(temp);
            if (g[i][j] == 'A')
                s = MP(i, j);
            if (g[i][j] == 'B')
                e = MP(i, j);
        }
    }
    dis.assign(n, vector<int>(m, -1));
    bfs(s, e);
    if (dis[e.F][e.S] == -1)
        cout << "NO" << endl;
    else
    {
        string str = "";
        cout << "YES" << endl;
        cout << dis[e.F][e.S] << endl;
        state curr = e;
        state track = curr;
        while (curr != make_pair(-1, -1))
        {
            track = par[curr.F][curr.S];
            if (track == make_pair(-1, -1))
                break;
            if (curr.F - track.F == 1)
                str.push_back('D');
            else if (track.F - curr.F == 1)
                str.push_back('U');
            else if (track.S - curr.S == 1)
                str.push_back('L');
            else if (curr.S - track.S == 1)
                str.push_back('R');
            curr = track;
        }
        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}