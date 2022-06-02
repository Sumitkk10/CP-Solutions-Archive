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
    ll a[n];
    vector<pair<ll, int> > v;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    map<int, int> mp;
    for(int i = 0; i < v.size(); ++i)
        mp[v[i].second] = i;
    ll ans = 1;
    for(int i = 1; i < n; ++i){
        if(mp[i] == mp[i - 1] + 1) continue;
        ++ans;
    }
    cout << (ans <= k ? "Yes\n" : "No\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
