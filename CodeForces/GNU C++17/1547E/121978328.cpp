#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    long long int a[k + 1], t[k + 1];
    map<long long int, int> mp;
    for(int i = 1; i <= k; ++i){
        cin >> a[i];
        mp[a[i]] = i;
    }
    for(int i = 1; i <= k; ++i)
        cin >> t[i];
    long long suf_mx[n + 1], pre_mx[n + 1];
    pre_mx[0] = INT_MAX;
    suf_mx[n + 1] = INT_MAX;
    for(int i = 1; i <= n; ++i){
        if(mp[i])
            pre_mx[i] = min(pre_mx[i - 1], t[mp[i]] - a[mp[i]]);
        else
            pre_mx[i] = pre_mx[i - 1];
    }
    for(int i = n; i >= 1; --i){
        if(mp[i])
            suf_mx[i] = min(suf_mx[i + 1], t[mp[i]] + a[mp[i]]);
        else
            suf_mx[i] = suf_mx[i + 1];
    }
    for(int i = 1; i <= n; ++i)
        cout << min(pre_mx[i] + i, suf_mx[i] - i) << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
