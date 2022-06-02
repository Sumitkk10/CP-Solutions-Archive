#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m;
// those which are not connected forwards will not die no matter wut.
vector<int> graph[N], temp[N];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int bad[n + 1];
    memset(bad, 0, sizeof bad);
    for(int i = 1; i <= n; ++i){
        for(auto k : graph[i])
            if(k > i)
                ++bad[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        if(!bad[i])
            ++ans;
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            if(v > u){
                if(bad[u] == 0) --ans;
                ++bad[u];
            }
            else{
                if(bad[v] == 0) --ans;
                ++bad[v];
            }
        }
        if(type == 2){
            int u, v;
            cin >> u >> v;
            if(u > v){
                if(bad[v] == 1) ++ans;
                bad[v]--;
            }
            else{
                if(bad[u] == 1) ++ans;
                bad[u]--;
            }
        }
        if(type == 3)
            cout << ans << "\n";
    }
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
