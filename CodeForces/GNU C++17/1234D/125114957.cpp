#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;
int n, a[N], fenwick[N][26];

void upd(int i, int j, int val){
    for(int pos = i; pos <= n; pos += (pos & -pos))
        fenwick[pos][j] += val;
}

int get(int i, int j){
    int ans = 0;
    for(int pos = i; pos >= 1; pos -= (pos & -pos))
        ans += fenwick[pos][j];
    return ans;
}

void solve(){
    cin >> s;
    n = s.size();
    for(int i = 1; i <= s.size(); ++i)
        a[i] = s[i - 1] - 'a';
    for(int i = 1; i <= s.size(); ++i)
        upd(i, a[i], 1);
    int q;
    cin >> q;
    for(int i = 1; i <= q; ++i){
        int type;
        cin >> type;
        if(type == 1){
            int pos;
            char c;
            cin >> pos >> c;
            upd(pos, a[pos], -1);
            a[pos] = c - 'a';
            upd(pos, a[pos], 1);
            continue;
        }
        int l, r, ans = 0;
        cin >> l >> r;
        for(int i = 0; i < 26; ++i)
            ans += (get(r, i) - get(l - 1, i) > 0 ? 1 : 0);
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
