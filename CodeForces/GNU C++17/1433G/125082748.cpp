#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
ll n, m, k, dp[N][N];
vector<pair<int, int> > graph[N];
vector<pair<ll, pair<int, int> > > edges;

void dijksta(int source){
    dp[source][source] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int > >, greater<pair<ll, int> > > pq;
    pq.push({0, source});
    while(!pq.empty()){
        ll cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto k : graph[node]){
            if(dp[source][k.first] > cost + k.second){
                dp[source][k.first] = cost + k.second;
                pq.push({cost + k.second, k.first});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = INT_MAX;
    for(int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
        edges.push_back({c, {u, v}});
    }
    for(int i = 1; i <= n; ++i)
        dijksta(i);
    vector<pair<int, int> > q(k + 1);
    for(int i = 1; i <= k; ++i)
        cin >> q[i].first >> q[i].second;
    /*
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j)
            cout << (dp[i][j] == INT_MAX ? -1 : dp[i][j]) << " ";
        cout << endl;
    }
    */
    ll ans = INT_MAX;
    for(int i = 0; i < edges.size(); ++i){
        ll c = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        ll res = 0;
        for(int i = 1; i <= k; ++i){
            int x1 = q[i].first, y1 = q[i].second;
            res += min({dp[x1][y1], dp[x1][u] + dp[v][y1], dp[y1][u] + dp[v][x1], dp[x1][u] + dp[u][y1], dp[x1][v] + dp[v][y1]});
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
