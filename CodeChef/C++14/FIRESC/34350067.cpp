#include <bits/stdc++.h>
#define ll long long int    
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7, N = 1e5 + 3;
vector<ll> graph[N];
ll n, m, mx = 0;
bool vis[N];

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) %  MOD);
}

void dfs(ll id){
    vis[id] = true;
    ++mx;
    for(int i = 0; i < graph[id].size(); ++i){
        if(vis[graph[id][i]] == false)
            dfs(graph[id][i]);
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= m; ++i){
            ll x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        ll cnt = 0;
        vector<ll> siz;
        for(int i = 1; i <= n; ++i){
            if(vis[i] == false){
                dfs(i);
                ++cnt;
                siz.push_back(mx);
            }
            mx = 0;
        }
        cout << cnt << ' ';
        ll mult = 1;
        for(int i = 0; i < siz.size(); ++i)
            mult = mul(mult, siz[i]);
        cout << mult << '\n';
        for(int i = 0; i < N; ++i){
            vis[i] = 0;
            graph[i].clear();
        }
    }
    return 0;
}