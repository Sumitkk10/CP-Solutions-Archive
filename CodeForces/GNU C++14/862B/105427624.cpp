#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
vector<int> graph[N], ans(N, 0);
bool vis[N];

void dfs(int source, bool ok){
    vis[source] = 1;
    ans[source] = ok + 1;
    for(auto k : graph[source])
        if(!vis[k])
            dfs(k, !ok);
}

int main() {
    fast;
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i, 0);
    long long int cnt_l = 0, cnt_r = 0;
    for(int i = 1; i <= n; ++i) {
        cnt_l += (ans[i] == 1);
        cnt_r += (ans[i] == 2);
    }
    long long ans = cnt_l * cnt_r;
    cout << ans - n + 1 << '\n';
    return 0;
}