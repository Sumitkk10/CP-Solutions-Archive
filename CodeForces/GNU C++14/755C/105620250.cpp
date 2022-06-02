#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 100000 + 5;
const int MOD = 1e9 + 7;
int n, p[N];
vector<int> tree[N];
bool vis[N];

void dfs(int source){
    vis[source] = 1;
    for(auto k : tree[source])
        if(!vis[k])
            dfs(k);
}

int main() {
    fast;
//    freopen("cbarn.in", "r", stdin);
//    freopen("cbarn.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        tree[i].push_back(p[i]);
        tree[p[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}