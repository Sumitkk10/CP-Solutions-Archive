#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 3e5 + 5;
const int MOD = 998244353;
vector<ll> graph[N];
ll n, m, one, two, ans, color[N];
bool vis[N], vis1[N];

void dfs(int node, int col){
    vis[node] = true;
    color[node] = col;
    if(col == 0) ++one;
    else ++two;
    for(auto k : graph[node]){
        if(vis[k]) continue;
        dfs(k, col ^ 1);
    }
}

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

bool check(int i, int p){
    bool cur = 1;
    vis1[i] = true;
    for(auto k : graph[i]){
        if(color[k] == color[i])
            return cur = false;
        if(!vis1[k])
            cur = (cur & check(k, i));
    }
    return cur;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans = 1;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            one = two = 0;
            dfs(i, 0);
            if(check(i, 0))
                ans = mul(ans, ad(power(2, two), power(2, one)));
            else{
                cout <<"0\n";
                for(int i = 1; i <= n; ++i){
                    graph[i].clear();
                    vis[i] = vis1[i] = 0;
                }
                return;
            }
        }
    }
    cout << ans << "\n";
    for(int i = 1; i <= n; ++i){
        graph[i].clear();
        vis[i] = vis1[i] = 0;
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
