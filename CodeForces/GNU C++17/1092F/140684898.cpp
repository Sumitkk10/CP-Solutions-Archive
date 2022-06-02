#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
vector<pair<int, int> > graph[N];
long long int in[N], out[N], subtree_size[N], pop[N];

// subtree_size[i] denotes the population of all cities in subtree of ith city excluding the ith city;

void yet_another_dfs(int source, int p){
    subtree_size[source] = 0;
    for(auto k : graph[source]) {
        if (k.first != p) {
            yet_another_dfs(k.first, source);
            subtree_size[source] += pop[k.first] + subtree_size[k.first];
        }
    }
}

void dfs(int source, int p){
    in[source] = 0;
    for(auto k : graph[source]){
        if(k.first != p){
            dfs(k.first, source);
            in[source] += in[k.first] + (k.second * (subtree_size[k.first] + pop[k.first]));
        }
    }
}

void dfs1(int source, int p) {
    // going to siblings
    for(auto k : graph[source]){
        if(k.first != p){
            long long cur = in[source] - (in[k.first] + ((subtree_size[k.first] + pop[k.first]) * k.second)) + ((subtree_size[source] - (subtree_size[k.first] + pop[k.first])) * k.second);
            out[k.first] = cur + out[source] + (subtree_size[1] + pop[1] - subtree_size[source]) * k.second;
            dfs1(k.first, source);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> pop[i];
    for(int i = 1; i <= n - 1; ++i) {
        long long int u, v, c;
        cin >> u >> v;
        c = 1;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    yet_another_dfs(1, 0);
    dfs(1, 0);
    dfs1(1, 0);
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, in[i] + out[i]);
     cout << ans << '\n';
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}