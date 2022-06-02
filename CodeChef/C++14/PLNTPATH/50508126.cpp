#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e6 + 5;
const int MOD = 1e9 + 7;
long long n, k, s, component[N], distance1[N];
vector<pair<ll, ll> > graph[N];

void dijkstra(int node){
    distance1[node] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, node});
    while(!pq.empty()){
        int node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        for(auto kk : graph[node]){
            if(distance1[kk.first] > cost + kk.second){
                distance1[kk.first] = cost + kk.second;
                pq.push({distance1[kk.first], kk.first});
            }
        }
    }
}

void solve(){
    cin >> n >> k >> s;
    // n --> plants, k --> components, s --> source node;
    // free to travel in one component;
    for(int i = 1; i <= n; ++i)
        cin >> component[i];
    for(int i = 1; i <= k; ++i)
        distance1[i] = LLONG_MAX;
    for(int i = 1; i <= n; ++i){
        int comp = component[i];
        for(int j = 1; j <= k; ++j){
            ll x;
            cin >> x;
            if(x != -1)
                graph[comp].push_back({j, x});
        }
    }
    int cur = component[s];
    dijkstra(cur);
    vector<ll> ans(n + 1, -1);
    for(int i = 1; i <= n; ++i){
        if(component[i] == cur){
            ans[i] = 0;
            continue;
        }
        int x = component[i];
        ans[i] = distance1[x];
    }
    for(int i = 1; i <= n; ++i)
        cout << (ans[i] == LLONG_MAX ? -1 : ans[i]) << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
