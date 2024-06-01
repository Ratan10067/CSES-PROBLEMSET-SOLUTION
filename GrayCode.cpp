#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define pi 3.14
class Solution
{
public:
    vector<string> graycode(int n)
    {
        vector<string> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            int temp = i;
            vector<int> v(n, 0);
            int j = n - 1;
            while (temp != 0)
            {
                v[j] = temp % 2;
                j--;
                temp /= 2;
            }
            vector<int> arr(n);
            arr[0] = v[0];
            for (int i = 1; i < n; i++)
            {
                arr[i] = v[i] ^ v[i - 1];
            }
            string s = "";
            for (int i = 0; i < n; i++)
            {
                s.append(to_string(arr[i]));
            }
            ans.push_back(s);
        }
        return ans;
    }
};
signed main()
{
    while (true)
    {
        cout<<2<<endl;
    }
    int t;
    cin >> t;
    vector<string> ans;
    Solution s1;
    ans = s1.graycode(t);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}