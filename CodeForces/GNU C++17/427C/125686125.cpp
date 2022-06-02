#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, m, a[N], par[N];
pair<ll, ll> ok[N];
vector<int> graph[N], transpose[N], order, component, condensation[N];
bool vis[N];

void dfs(int node){
    vis[node] = true;
    for(auto k : graph[node])
        if(!vis[k])
            dfs(k);
    order.push_back(node);
}

void dfs1(int node){
    vis[node] = true;
    for(auto k : transpose[node])
        if(!vis[k])
            dfs1(k);
    component.push_back(node);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof vis);
    for(auto k : order){
        if(vis[k]) continue;
        dfs1(k);
        // we try to build condensation graph here.
        ll mn = INT_MAX, cnt = 0;
        for(auto k : component){
            // cout << k << " ";
            par[k] = component[0];
            if(a[k] < mn){
                mn = a[k];
                cnt = 1;
            }
            else if(a[k] == mn)
                ++cnt;
        }
        ok[component[0]] = {mn, cnt};
        component.clear();
    }
    memset(vis, 0, sizeof vis);
    ll ans = 0, ans1 = 1;
    for(int i = 1; i <= n; ++i){
        if(vis[par[i]]) continue;
        ans += ok[par[i]].first;
        ans1 = (ans1 * ok[par[i]].second) % MOD;
        vis[par[i]] = true;
    }
    cout << ans << " " << ans1 << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
