#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> ans, graph[N];
int n, m, dis[N];
bool vis[N];

void bfs(int node){
    vis[node] = true;
    queue<pair<int, int> > q;
    q.push({node, 1});
    while(!q.empty()){
        int node = q.front().first, col = q.front().second;
        dis[node] = col;
        q.pop();
        for(auto k : graph[node]){
            if(!vis[k]){
                q.push({k, col + 1});
                vis[k] = true;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    vector<int> odd, even;
    for(int i = 1; i <= n; ++i){
        if(dis[i] % 2) odd.push_back(i);
        else even.push_back(i);
    }
    cout << min(odd.size(), even.size()) << '\n';
    if(odd.size() < even.size())
        for(auto k : odd) cout << k << ' ';
    else
        for(auto k : even) cout << k << ' ';
    for(int i = 0; i <= n; ++i){
        graph[i].clear();
        dis[i] = 0;
        vis[i] = 0;
    }
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}