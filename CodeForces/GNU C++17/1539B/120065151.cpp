#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<pair<int, int> , int> mp;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < 26; ++j)
            mp[{i, j}] = mp[{i- 1, j}];
        mp[{i, s[i - 1] - 'a'}]++;
    }
    while(q--){
        long long int l, r;
        cin >> l >> r;
        long long ans = 0;
        for(int j = 0; j < 26; ++j){
            long long int cnt = mp[{r, j}] - mp[{l - 1, j}];
            ans += (cnt * (j + 1));
        }
        cout << ans << '\n';
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
