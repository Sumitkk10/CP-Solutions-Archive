#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;
ll r, c, n, cnt;
set<pair<ll, ll> > s;
map<pair<ll, ll>, ll> mp;
vector<pair<ll, ll> > ans[N];

void dfs(ll x, ll y){
    mp[{x, y}]++;
    if(s.find({x, y}) != s.end()){
        ans[cnt].pb({x, y});
        if(mp[{x + 1, y}] == 0) dfs(x + 1, y);
        if(mp[{x - 1, y}] == 0) dfs(x - 1, y);
        if(mp[{x, y + 1}] == 0) dfs(x, y + 1);
        if(mp[{x, y - 1}] == 0) dfs(x, y - 1);
    }
}

int main(){
    fast;
    cin >> r >> c >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i){
        ll x, y;
        cin >> x >> y;
        s.insert({x, y});
        a[i].first = x;
        a[i].second = y;
    }
    for(int i = 0; i < n; ++i){
        ll x = a[i].first;
        ll y = a[i].second;
        if(mp[{x, y}] != 0) continue;
        dfs(x, y);
        ++cnt;
    }
    ll mx = 0;
    for(int i = 0; i < cnt; ++i){
        ll sum = 0;
        for(int j = 0; j < ans[i].size(); ++j){
            if(s.find({ans[i][j].first + 1, ans[i][j].second}) == s.end()) ++sum; 
            if(s.find({ans[i][j].first, ans[i][j].second + 1}) == s.end()) ++sum;
            if(s.find({ans[i][j].first, ans[i][j].second - 1}) == s.end()) ++sum;
            if(s.find({ans[i][j].first - 1, ans[i][j].second}) == s.end()) ++sum;
        }
        mx = max(mx, sum);
    }
    cout << mx;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}