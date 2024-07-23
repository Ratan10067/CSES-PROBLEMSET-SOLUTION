#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(false)
#define pi 3.14
#define F first
#define S second
#define MP make_pair
map<int,int> mp;
string str = "";
string s = "";
int cnt = 0;
vector<string> ans;
void rec(int level)
{
    if(level==s.size())
    {
        if(str.size()==s.size())
        {
            cnt++;
            ans.push_back(str);
        }
    }
    for(auto i:mp)
    {
        if(i.second!=0)
        {
            mp[i.first]--;
            str.push_back(i.first);
            rec(level+1);
            str.pop_back();
            mp[i.first]++;
        }
    }
}
signed main()
{
    cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    rec(0);
    cout<<cnt<<endl;
    for(auto i:ans)cout<<i<<endl;
    return 0;
}