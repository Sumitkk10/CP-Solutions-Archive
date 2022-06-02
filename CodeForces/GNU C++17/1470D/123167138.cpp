#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N], ans;
int n, m, conn;
bool vis[N], vis1[N];

void dfs(int node){
    vis1[node] = true;
    ++conn;
    for(auto k : graph[node])
        if(!vis1[k])
            dfs(k);
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(!vis[node]){
            vis[node] = true;
            ans.push_back(node);
            for(auto k : graph[node]){
                if(!vis[k]){
                    for(auto kk : graph[k])
                        if(!vis[kk])
                            q.push(kk);
                }
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
    dfs(1);
    if(conn < n){
        cout << "NO\n";
        for(int i = 1; i <= n; ++i){
            graph[i].clear();
            vis[i] = false;
            vis1[i] = false;
        }
        ans.clear();
        conn = 0;
        return;
    }
    conn = 0;
    bfs(1);
    cout << "YES\n" << ans.size() << '\n';
    for(auto k : ans) cout << k << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i){
        graph[i].clear();
        vis[i] = false;
        vis1[i] = false;
    }
    ans.clear();
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
