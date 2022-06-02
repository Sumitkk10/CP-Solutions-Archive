#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;
int n, a[N], dp[N][2];
vector<int> tree[N];
bool vis[N];

void dfs(int source){
    vis[source] = 1;
    dp[source][0] = a[source];
    for(auto k : tree[source]) {
        if (!vis[k]) {
            dfs(k);
            dp[source][0] += dp[k][1];
            dp[source][1] += max(dp[k][0], dp[k][1]);
        }
    }
}

int main() {
    fast;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}
