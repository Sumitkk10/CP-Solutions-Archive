#include <bits/stdc++.h>
#define ll long long int    
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll MOD = 1e9 + 7, N = 1e6+3, INF = 1e9 + 2;
vector<pair<ll, ll> > graph[N];
ll dest, strt;
vector<ll> d(N);

void dijkstra(ll strt){
    set<pair<ll, ll> > q;
    d[strt] = 0;
    q.insert({0, strt});
    while(q.empty() == false){
        ll v = q.begin()->second;
        q.erase(q.begin());
        for(auto edge : graph[v]){
            ll to = edge.first;
            ll len = edge.second;
            if(d[v] + len < d[to]){
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    } 
}

int main() {
    fast;
    ll n, m, x, y;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        cin >> x >> y;
        graph[x].push_back({y, 1});
        graph[y].push_back({x, 1});
    }
    cin >> strt >> dest;
    for(int i = 0; i < N; ++i)
        d[i] = INF;
    dijkstra(strt);
    if(d[dest] == INF)
        cout << 0;
    else
        cout << d[dest];
    return 0;
}