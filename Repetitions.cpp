#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "";
    cin >> str;
    int ans = INT_MIN;
    int cnt = 1;
    for (int i = 0; i < (int)str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}