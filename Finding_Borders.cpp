#include "bits/stdc++.h"
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
vector<int> kmp;
// struct hasher
// {
//     int _mod;
//     int _p;
//     int sz;
//     vector<int> fhash;
//     vector<int> revhash;
//     vector<int> pk;

//     void init(string &s, int p, int mod)
//     {
//         sz = s.length();
//         _p = p;
//         _mod = mod;
//         fhash.resize(sz);
//         revhash.resize(sz);
//         pk.resize(sz);
//         pk[0] = 1;
//         fhash[0] = (s[0] - 'a' + 1);
//         revhash[sz - 1] = (s[sz - 1] - 'a' + 1);
//         for (int i = 1; i < sz; i++)
//         {
//             fhash[i] = (1LL * fhash[i - 1] * p + s[i] - 'a' + 1) % _mod;
//             pk[i] = (pk[i - 1] * p) % _mod;
//         }
//         for (int i = sz - 2; i >= 0; i--)
//         {
//             revhash[i] = (1LL * revhash[i + 1] * p + s[i] - 'a' + 1) % _mod;
//         }
//     }

//     int gethash(int l, int r)
//     {
//         if (l == 0)
//             return fhash[r] % _mod;
//         int ans = (fhash[r] - 1LL * fhash[l - 1] * pk[r - l + 1]) % _mod;
//         return (ans + _mod) % _mod;
//     }

//     int getrevhash(int l, int r)
//     {
//         if (r == sz - 1)
//             return revhash[l] % _mod;
//         int ans = (revhash[l] - 1LL * revhash[r + 1] * pk[r - l + 1]) % _mod;
//         return (ans + _mod) % _mod;
//     }
// };
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
    cin >> str;
    int n = str.length();
    kmp.resize(n + 1);
    buildKMPArray(str);
    int temp = kmp[n];
    vector<int> v;
    while (temp != -1)
    {
        v.push_back(temp);
        temp = kmp[temp];
    }
    v.pop_back();
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}