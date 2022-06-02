#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<string> perm = {"abc", "acb", "bca", "bac", "cab", "cba"};
vector<vector<int> > pre(N, vector<int>(6, 0));

void solve(){
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    for(int j = 0; j < 6; ++j){
        int wut = s.size()/3;
        string cur = "";
        while(wut--)
            cur += perm[j];
        for(int lst = 0; lst < s.size()%3; ++lst)
            cur.push_back(perm[j][lst]);
        cur = " " + cur;
        for(int i = 1; i <= s.size(); ++i)
            pre[i][j] = pre[i - 1][j] + (s[i] != cur[i]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        for(int j = 0; j < 6; ++j)
            ans = min(ans, pre[r][j] - pre[l - 1][j]);
        cout << ans << "\n";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
