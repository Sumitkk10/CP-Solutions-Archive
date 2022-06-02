#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;
ll n, m, k, cost[N], cost1;
vii graph[N];
bool vis[N];

void dfs(int n){
    vis[n] = true;
    cost1 += cost[n];
    for(auto i : graph[n])
        if(!vis[i])
            dfs(i);
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 1; i <= m; ++i){
            ll u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        for(int i = 1; i <= n; ++i)
            cin >> cost[i];
        vii ans;
        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                dfs(i);
                ans.pb(cost1);
                cost1 = 0;
            }
        }
        if(k > ans.size()) cout << "-1\n";
        else{
            // cout << ans.size() << " ";
            int realans = 0, l = 0, r = 1, i = 0;
            sort(ans.rbegin(), ans.rend());
            while(k--){
                if(i % 2 == 0){ 
                    realans += ans[l];
                    ++l;
                }
                else{ 
                    realans += ans[ans.size() - r];
                    ++r;
                }
                ++i;
            }
            cout << realans << "\n";
        }
        for(int i = 0; i < N; ++i){
            graph[i].clear();
            vis[i] = 0;
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}