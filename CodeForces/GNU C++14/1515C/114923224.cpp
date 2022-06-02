#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    int b[n];
    vector<pair<int, int> > a;
    set<pair<int, int> > s; 
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        a.push_back({b[i], i});
    }
    for(int i = 0; i < m; ++i)
        s.insert({0, i});
    vector<int> ans(n, 0);
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < a.size(); ++i){
        ans[a[i].second] = (*s.begin()).second;
        int x = (*s.begin()).first, xx = (*s.begin()).second;
        s.erase(s.begin());
        s.insert({x + a[i].first, xx});
    }
    map<int, int> mp;
    for(int i = 0; i < n; ++i)
        mp[ans[i]] += b[i];
    int mx = 0, mn = INT_MAX;
    for(auto k : mp){
        mx = max(mx, k.second);
        mn = min(mn, k.second);
    }
    if(mx - mn > x){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto k : ans)
        cout << k + 1 << ' ';
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
