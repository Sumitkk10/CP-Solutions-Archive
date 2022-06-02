#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e2 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
vector<vector<int> > cnt;
int n, k;

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

void dfs(int node, int height, int id, int p){
    cnt[height][id]++;
    for(auto k : graph[node]){
        if(k == p) continue;
        dfs(k, height + 1, id, node);
    }
}

long long select(vector<int>& a){
    sort(a.rbegin(), a.rend());
    while(!a.empty() and a.back() == 0) a.pop_back();
    if(a.size() < k)
        return 0;
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < a.size(); ++i)
        for(int nodes = k; nodes > 0; --nodes)
            dp[nodes] = add(dp[nodes], mul(dp[nodes - 1], a[i]));
    return dp[k];
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for(int root = 1; root <= n; ++root){
        if(graph[root].size() < k) continue;
        cnt.assign(n + 1, vector<int>(graph[root].size(), 0));
        for(int node = 0; node < graph[root].size(); ++node)
            dfs(graph[root][node], 0, node, root);
        for(auto& a : cnt)
            ans = add(ans, select(a));
    }
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
    if(k == 2){
        cout << (n * (n - 1)) / 2 << '\n';
        return;
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
