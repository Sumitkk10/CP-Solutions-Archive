#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, m, k;
map<int, ll> cost;
ll dis[N];
vector<pair<int, int> > graph[N];

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        cost[i] = -1;
        dis[i] = 1e16;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    for(int i = 1; i <= k; ++i){
        long long x, c;
        cin >> x >> c;
        cost[x] = c;
        pq.push({c, x});
        dis[x] = c;
    }
    for(int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    // just like a multi-source bfs
    // a multi-source dijkstra will work, ig.
    while(!pq.empty()){
        ll cost = pq.top().first, node = pq.top().second;
        pq.pop();
        for(auto k : graph[node]){
            if(dis[k.first] > cost + k.second){
                dis[k.first] = cost + k.second;
                pq.push({dis[k.first], k.first});
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << dis[i] << " ";
        graph[i].clear();
    }
    cout << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}