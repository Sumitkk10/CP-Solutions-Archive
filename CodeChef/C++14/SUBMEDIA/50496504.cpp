#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, k;
    cin >> n >> k;
    pair<ll, ll> a[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    vector<pair<int, int> > ans;
    for(int i = n; i > (n - k); --i)
        ans.push_back({a[i].second, a[i].first});
    cout << ans[ans.size() / 2].second << '\n';
    sort(ans.begin(), ans.end());
    for(auto k : ans) 
        cout << k.second << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
