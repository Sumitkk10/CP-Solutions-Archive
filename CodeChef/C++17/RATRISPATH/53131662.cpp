#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<pair<int, int> > dis(N, {1e9, 0});
vector<int> graph[N];
map<pair<int, int>, bool> mp;
map<int, int> pos;
int n, m;

void bfs(int nn){
    dis[nn].first = 0;
    dis[nn].second = nn;
    queue<int> q;
    q.push(nn);
    bool vis[n + 1];
    memset(vis, 0, sizeof vis);
    vis[nn] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto k : graph[node]){
            if(dis[k].first > dis[node].first + 1){
                dis[k].first = dis[node].first + 1;
                dis[k].second = k;
            }
            if(!vis[k]){
                q.push(k);
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
        mp[{u, v}] = mp[{v, u}] = true; 
    }
    bfs(1);
    sort(dis.begin(), dis.end());
    for(int i = 0; i < n; ++i)
        pos[dis[i].second] = i;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for(int i = 1; i < n; ++i){
        int x = dis[i].second;
        for(auto k : graph[x])
            if(dis[pos[k]].first + 1 == dis[i].first)
                dp[x] = (dp[x] + dp[k]) % MOD;
    }
    cout << dp[n] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
