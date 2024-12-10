#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
vector<int> kmp;
void buildKMP(string &s)
{
    kmp[0] = -1;
    int j = -1;
    int i = 0;
    while (i < s.size())
    {
        while (j != -1 and s[i] != s[j])
        {
            j = kmp[j];
        }
        i++;
        j++;
        kmp[i] = j;
    }
}
signed main()
{
    string text, pattern;
    cin >> text >> pattern;
    string s = pattern + '#' + text;
    kmp.resize(s.length() + 1);
    buildKMP(s);
    int ans = 0;
    for (int i = 0; i < kmp.size(); i++)
    {
        if (kmp[i] == pattern.size())
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}