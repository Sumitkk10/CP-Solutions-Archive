#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, m, w, a[N], fenwick[N];

void upd(int node, int val){
    for(int i = node; i <= n; i += (i & -i))
        fenwick[i] += val;
}

ll get(int node){
    ll ans = 0;
    for(int i = node; i >= 1; i -= (i & -i))
        ans += fenwick[i];
    return ans;
}

bool check(ll mid){
    for(int i = 1; i <= n + 1; ++i)
        fenwick[i] = 0;
    ll ok = 0;
    for(int i = 1; i <= n; ++i){
        ll cur = get(i);
        if(a[i] + cur >= mid) continue;
        ll res = mid - (a[i] + cur);
        ok += res;
        if(ok > m) return false;
        upd(i, res);
        upd(min(n + 1, i + w), -res);
    }
    return true;
}

void solve(){
    cin >> n >> m >> w;
    ll mn = 0;
    for(int i = 1; i <= n; ++i){ 
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ll low = mn, high = 1e15, ans = 0;
    while(low <= high){
        ll mid = (low + (high - low)/2);
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
