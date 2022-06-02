#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, component[N], ans, c[N], k[N];
pair<ll, ll> points[N];
vector<pair<long long, pair<int, int> > > edges;
vector<int> res;
vector<pair<int, int> > res1;

int find(int x){
    while(true){
        if(x == component[x])
            return x;
        component[x] = component[component[x]];
        x = component[x];
    }
}

void merge(int u, int v){
    int a = find(u), b = find(v);
    component[a] = b;
}

void MST(){
    for(int i = 0; i < edges.size(); ++i){
        ll cost = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
        if(find(u) == find(v)) continue;
        if(u == 0)
            res.push_back(v);
        else
            res1.push_back({u, v});
        // cout << u << " " << v << " " << cost << "\n";
        ans += cost;
        merge(u, v);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n; ++i)
        component[i] = i;
    for(int i = 1; i <= n; ++i)
        cin >> points[i].first >> points[i].second;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
        cin >> k[i];
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j)
            edges.push_back({(k[i] + k[j]) * (abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second)), {i ,j}});
        edges.push_back({c[i], {0, i}});
    }
    sort(edges.begin(), edges.end());
    MST();
    cout << ans << "\n" << res.size() << "\n";
    for(auto k : res) cout << k << " ";
    cout << "\n" << n - res.size() << "\n";
    for(auto k : res1)
        cout << k.first << " " << k.second << "\n"; 
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}