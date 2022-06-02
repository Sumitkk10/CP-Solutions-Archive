#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll long long
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, u[N], v[N];
vector<int> g[N];
map<pair<int, int>, int> ans;

void dfs(int root, int par, int pre){
    int cur = 2;
    if(pre == 2)
        ++cur;
    ans[{par, root}] = pre;
    ans[{root, par}] = pre;
    for(auto k : g[root]){
        if(k == par) continue;
        dfs(k, root, cur);
        ++cur;
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n; ++i)
        g[i].clear();
    map<int, int> deg;
    for(int i = 0; i < n - 1; ++i){
        cin >> u[i] >> v[i];
        deg[u[i]]++;
        deg[v[i]]++;
        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }
    for(auto k : deg){
        if(k.second > 2){
            cout << "-1\n";
            return;
        }
    }
    dfs(1, 0, 3);
    for(int i = 0; i < n - 1; ++i){
        cout << ans[{u[i], v[i]}] << ' ';
    }
    cout << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}