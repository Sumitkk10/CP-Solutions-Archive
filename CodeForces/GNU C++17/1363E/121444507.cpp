#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long int n, a[N], b[N], c[N], ans = 0;
vector<int> graph[N];
bool vis[N];

pair<int, int> dfs(int node, int p){
    vis[node] = true;
    int ct = 0, ct1 = 0;
    if(b[node] != c[node]){
        if(c[node] == 0)
            ++ct;
        else
            ++ct1;
    }
    a[node] = min(a[node], a[p]);
    for(auto k : graph[node]){
        if(!vis[k]){
            pair<int, int> cur = dfs(k, node);
            ct += cur.first;
            ct1 += cur.second;
        }
    }
    int mn = min(ct, ct1);
    ans += 2*mn*a[node];
    ct -= mn;
    ct1 -= mn;
    return {ct, ct1};
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    pair<int, int> ok = dfs(1, 1);
    if(ok.first > 0 or ok.second > 0){
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}
int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
