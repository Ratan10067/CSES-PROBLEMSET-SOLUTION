#include "bits/stdc++.h"
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
vector<int> kmp;
void buildKMPArray(string &s)
{
    kmp[0] = -1;
    int i = 0;
    int j = -1;
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
    IOS;
    string str;
    cin>>str;
    kmp.resize(str.length() + 1);
    buildKMPArray(str);
    vector<int> v;
    int temp = kmp[str.size()];
    while (temp != -1)
    {
        v.push_back(str.size() - temp);
        temp = kmp[temp];
    }
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}