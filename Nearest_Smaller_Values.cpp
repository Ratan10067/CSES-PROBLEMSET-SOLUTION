#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios_base::sync_with_stdio(false)
signed main()
{
    IOS;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            v.push_back(0);
        else
        {
            v.push_back(st.top() + 1);
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}