#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
vector<pair<int, bool> > graph[N];
vector<int> ans;
bool vis[N], flg;
int n;

void dfs(int source){
    vis[source] = 1;
    for(auto k : graph[source]){
        if(!vis[k.first]){
            if(k.second == 1) {
                if(flg)
                    ans.pop_back();
                ans.push_back(k.first);
                flg = 1;
            }
            dfs(k.first);
        }
    }
    if(!ans.empty() and source == ans[ans.size() - 1])
        flg = 0;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int u, v, type;
        cin >> u >> v >> type;
        --type;
        graph[u].push_back({v, type});
        graph[v].push_back({u, type});
    }
    // 0 --> no problem;
    // 1 --> problem;
    dfs(1);
    cout << ans.size() << "\n";
    for(auto k : ans)
        cout << k << ' ';
}

int main() {
    fast;
    int t = 1;
    while(t--)
        solve();
    return 0;
}