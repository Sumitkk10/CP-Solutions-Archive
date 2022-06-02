#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;
long long int n;
vector<long long int> tree[N];
bool vis[N];

long double dfs(int source){
    vis[source] = 1;
    long double ans = 0;
    for(auto k : tree[source])
        if(!vis[k])
            ans += dfs(k) + 1;
    return ans ? (long double) (ans / (tree[source].size() - (source != 1))) : 0;
}

int main() {
    fast;
//    freopen("cbarn.in", "r", stdin);
//    freopen("cbarn.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    long double ans = dfs(1);
    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}