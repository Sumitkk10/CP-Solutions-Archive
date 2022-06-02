#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int check(string a, string b){
    int ans = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i])
            ++ans;
    }
    return ans;
}

void solve(){
    string s;
    cin >> s;
    int ans = INT_MAX;
    for(int i = 0; i <= s.size(); ++i){
        string cur;
        for(int j = 0; j < i; ++j)
            cur.push_back('0');
        for(int j = i; j < s.size(); ++j)
            cur.push_back('1');
        ans = min(ans, check(s, cur));
    }
    for(int i = 0; i <= s.size(); ++i){
        string cur;
        for(int j = 0; j < i; ++j)
            cur.push_back('1');
        for(int j = i; j < s.size(); ++j)
            cur.push_back('0');
        ans = min(ans, check(s, cur));
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
