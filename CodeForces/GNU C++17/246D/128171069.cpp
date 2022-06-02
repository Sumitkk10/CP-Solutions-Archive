#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n, m, col[N];
set<int> neighbour[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> col[i];
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        // cout << col[u] << ' ' << col[v] << '\n';
        if(col[u] != col[v]){
            neighbour[col[u]].insert(col[v]);
            neighbour[col[v]].insert(col[u]);
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i){
        int x = col[i];
        mx = max(mx, (int) neighbour[x].size());
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; ++i){
        int x = col[i];
        if(neighbour[x].size() == mx)
            ans = min(ans, x);
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
