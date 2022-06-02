#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e3 + 5;
int n, adjmat[N][N], component[N];
vector<pair<long long, pair<int, int> > > edges;
long long ans;

int find(int a){
    while(true){
        if(a == component[a])
            return a;
        component[a] = component[component[a]];
        a = component[a];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    component[u] = component[v];
}

void MST(){
    for(int i = 1; i <= edges.size(); ++i){
        long long cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(find(u) == find(v))
            continue;
        merge(u, v);
        ans += cost;
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        component[i] = i;
        for (int j = 1; j <= n; ++j)
            cin >> adjmat[i][j];
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            if(i == j) continue;
            edges.push_back({adjmat[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    MST();
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}