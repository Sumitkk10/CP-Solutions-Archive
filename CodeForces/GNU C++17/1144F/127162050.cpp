#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, m;
vector<int> graph[N];
bool no;
vector<int> color(N, -1);
bool vis[N];

void dfs(int node, int col, int p){
    vis[node] = true;
    color[node] = col;
    for(auto k : graph[node]){
        if(k == p) continue;
        if(color[k] == color[node]){
            no = true;
            return;
        }
        if(!vis[k])
            dfs(k, col ^ 1, node);
    }
}

void solve(){
    cin >> n >> m;
    vector<pair<int, int> > edges;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.push_back({u, v});
    }
    dfs(1, 0, 0);
    if(no){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < m; ++i){
        int u = edges[i].first, v = edges[i].second;
        if(color[u] == 0) cout << "0";
        else cout << "1";
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
