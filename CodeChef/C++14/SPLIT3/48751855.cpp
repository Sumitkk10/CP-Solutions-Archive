#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
int n, val[N], tin[N], cur = 1, tout[N], subtree[N];

void dfs(int node, int p){
    tin[node] = cur;
    subtree[node] = val[node];
    for(auto k : graph[node]){
        if(k != p){
            ++cur;
            dfs(k, node);
            subtree[node] += subtree[k];
        }
    }
    tout[node] = cur;
}

bool isanc(int u, int v){
    if(tin[u] <= tin[v] and tin[v] <= tout[u])
        return true;
    return false;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    int ans = INT_MAX;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            if(i == j and i == 1) continue;
            if(isanc(i, j))
                ans = min(ans, max({subtree[1] - subtree[i], subtree[i] - subtree[j], subtree[j]}));
            else if(isanc(j, i))
                ans = min(ans, max({subtree[1] - subtree[j], subtree[j] - subtree[i], subtree[i]}));
            else
                ans = min(ans, max({subtree[1] - subtree[i]- subtree[j], subtree[i], subtree[j]}));
        }
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
