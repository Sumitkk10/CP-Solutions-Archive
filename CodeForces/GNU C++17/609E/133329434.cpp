#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
using namespace std;
const int N = 200004;
const int MOD = 1e9 + 7;
vector<pair<int, ll> > graph[N];
vector<pair<ll, pair<int, int> > > edges;
ll component[N], mx[N][30], ans, n, m, u[N], v[N], c[N], dp[N][30], lvl[N];
map<pair<int, int>, bool> mp;

int find(int x){
    while(true){
        if(x == component[x])
            return x;
        component[x] = component[component[x]];
        x = component[x];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    component[u] = v;
}

void MST(){
    for(int j = 0; j < edges.size(); ++j){
        long long cc = edges[j].F;
        int uu = edges[j].S.F, vv = edges[j].S.S;
        if(find(uu) == find(vv)) continue;
        merge(uu, vv);
        ans += cc;
        mp[{uu, vv}] = mp[{vv, uu}] = true;
        graph[uu].push_back({vv, cc});
        graph[vv].push_back({uu, cc});
    }
}

void dfs(int node, int par, int level){
    dp[node][0] = par;
    lvl[node] = level;
    for(auto k : graph[node]){
        if(k.F != par){
            mx[k.F][0] = k.S;
            dfs(k.F, node, level + 1);
        }
    }
}

void init(){
    dfs(1, -1, 0);
    for(int j = 1; j <= 20; ++j){
        for(int i = 1; i <= n; ++i){
            if(dp[i][j - 1] != -1){
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
                mx[i][j] = max(mx[i][j - 1], mx[dp[i][j - 1]][j - 1]);
            }
            else
                mx[i][j] = mx[i][j - 1];
        }
    }
}

ll LCA(int a, int b){
    ll cur_mx = 0;
    if(lvl[a] > lvl[b])
        swap(a, b);
    int d = lvl[b] - lvl[a];
    while(d){
        int x = log2(d);
        cur_mx = max(cur_mx, mx[b][x]);
        b = dp[b][x];
        d -= pow(2, x);
    }
    if(a == b)
        return cur_mx;
    for(int i = 20; i >= 0; --i){
        if(dp[a][i] != dp[b][i] and dp[a][i] != -1 and dp[b][i]  != -1){
            cur_mx = max({cur_mx, mx[a][i], mx[b][i]});
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    cur_mx = max({cur_mx, mx[a][0], mx[b][0]});
    return cur_mx;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> u[i] >> v[i] >> c[i];
        edges.push_back({c[i], {u[i], v[i]}});
    }
    for(int i = 1; i <= n; ++i)
        component[i] = i;
    sort(edges.begin(), edges.end());
    MST();
    memset(dp, -1, sizeof dp);
    memset(mx, 0, sizeof mx);
    init();
    for(int i = 1; i <= m; ++i){
        if(mp[{u[i], v[i]}]) {
            cout << ans << '\n';
            continue;
        } 
        long long int p = LCA(u[i], v[i]);
        cout << ans + c[i] - p << "\n";
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