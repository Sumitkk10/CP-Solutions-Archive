#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> graph[N];
int n, ans;
bool vis[N];
map<int, int> mp;

void dfs(int son, int father){
    for(auto grandson : graph[son]){
        if(grandson != father){
            dfs(grandson, son);
            if(!vis[son] and !vis[grandson]){
                ans += 2;
                vis[son] = vis[grandson] = true;
                mp[son] = grandson;
                mp[grandson] = son;
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ans += 2;
            mp[i] = mp[graph[i][0]];
            mp[graph[i][0]] = i;
        }
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i) cout << mp[i] << ' ';
	return 0;
}
