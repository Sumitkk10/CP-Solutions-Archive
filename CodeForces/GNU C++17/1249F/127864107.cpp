#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e2 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
int n, k, a[N], dp[N][N];

void dfs(int node, int par){
    dp[node][0] = a[node];
    for(auto kk : graph[node]){
        if(kk == par) continue;
        dfs(kk, node);
    }
    for(int depth = 0; depth <= n; ++depth){
        if(!depth){
            for(auto kk : graph[node]){
                if(kk == par) continue;
                dp[node][depth] += dp[kk][max(0, k - depth - 1)];
            }
            continue;
        }
        for(auto kk : graph[node]){
            if(kk == par) continue;
            int cur = dp[kk][depth - 1];
            for(auto j : graph[node]){
                if(j == kk or j == par) continue;
                cur += dp[j][max(k - depth - 1, depth - 1)];
            }
            dp[node][depth] = max(dp[node][depth], cur);
        }
    }
    for(int depth = n; depth > 0; --depth)
        dp[node][depth - 1] = max(dp[node][depth - 1] , dp[node][depth]);
}

void solve(){
    cin >> n >> k;
    ++k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // let dp[i][depth] be the max sum of subset of vertices that we can take from the subtree 
    // of v such that the minimum depth of a selected node is atleast depth.
    dfs(1, 0);
    cout << dp[1][0] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
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
