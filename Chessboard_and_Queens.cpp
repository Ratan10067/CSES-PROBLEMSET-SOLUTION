#include <bits/stdc++.h>
using namespace std;

#define int long long
class Solution
{
private:
    int queens[10];
    int check(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            int j = queens[i];
            if (col == j or abs(row - i) == abs(col - j))
            {
                return 0;
            }
        }
        return 1;
    }
    void rec(int level, const int n, vector<vector<string>> &ans)
    {
        if (level == n)
        {
            vector<string> s;
            string str;
            for (int i = 0; i < n; i++)
                str.push_back('.');
            for (int i = 0; i < n; i++)
            {
                if (queens[i] != -1)
                {
                    str[queens[i]] = 'Q';
                    s.push_back(str);
                    str[queens[i]] = '.';
                }
            }
            if (!s.empty())
                ans.push_back(s);
            return;
        }
        for (int ch = 0; ch < n; ch++)
        {
            if (check(level, ch))
            {
                queens[level] = ch;
                rec(level + 1, n, ans);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        memset(queens, -1, sizeof(queens));
        vector<vector<string>> ans;
        rec(0, n, ans);
        return ans;
    }
};
signed main()
{
    
    return 0;
}