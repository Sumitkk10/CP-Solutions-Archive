#include <bits/stdc++.h>
#define ll long long int    
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7, N = 233, INF = 1e9 + 2;
vector<pair<ll, ll> > graph[N];
vector<ll> d[N];
ll n, m, mx = 0;

void dijkstra(ll strt){
    for(int i = strt; i <= n; ++i){
        set<pair<ll, ll> > q;
        d[i][i] = 0;
        q.insert({0, i});
        while(q.empty() == false){
            ll v = q.begin()->second;
            q.erase(q.begin());
            for(auto edge : graph[v]){
                ll to = edge.first;
                ll len = edge.second;
                if(d[i][v] + len < d[i][to]){
                    q.erase({d[i][to], to});
                    d[i][to] = d[i][v] + len;
                    q.insert({d[i][to], to});
                }
            }
        } 
    }
}

int main() {
    fast;
    ll x, y, p;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> x >> y >> p;
        graph[x].push_back({y, p});
        graph[y].push_back({x, p});
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            d[i].push_back(INF);
    dijkstra(1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(d[i][j] == INF)
                continue;
            mx = max(mx, d[i][j]);
        }
    }
    cout << mx;
    return 0;
}