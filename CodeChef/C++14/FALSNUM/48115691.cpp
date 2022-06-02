#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    if(s[0] != '1')
        s = "1" + s;
    else{
        string ans;
        ans.push_back(s[0]);
        ans.push_back('0');
        for(int i = 1; i < s.size(); ++i)
            ans.push_back(s[i]);
        s = ans;
    }
    cout << s << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
