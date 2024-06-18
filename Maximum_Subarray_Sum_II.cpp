#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
void max_sum_subarray(vector<int> arr, int L, int R)
{
    int n = arr.size();
    int pre[n];
    // calculating prefix sum
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    multiset<int> mt;

    // maintain 0 for initial
    // values of i upto R
    // Once i = R, then
    // we need to erase that 0 from
    // our multiset as our first
    // index of subarray
    // cannot be 0 anymore.
    mt.insert(0);
    int ans = INT_MIN;

    ans = max(ans, pre[L - 1]);

    // we maintain flag to
    // counter if that initial
    // 0 was erased from set or not.
    int flag = 0;

    for (int i = L; i < n; i++)
    {

        // erase 0 from multiset once i=b
        if (i - R >= 0)
        {
            if (flag == 0)
            {
                auto it = mt.find(0);
                mt.erase(it);
                flag = 1;
            }
        }
        // insert pre[i-L]
        if (i - L >= 0)
            mt.insert(pre[i - L]);

        // find minimum value in multiset.
        ans = max(ans, pre[i] - *mt.begin());

        // erase pre[i-R]
        if (i - R >= 0)
        {
            auto it = mt.find(pre[i - R]);
            mt.erase(it);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    max_sum_subarray(nums, a, b);
    return 0;
}