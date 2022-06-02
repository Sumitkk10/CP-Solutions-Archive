#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int component[N], size_comp[N];

int find(int x){
    while(1){
        if(x == component[x])
            return x;
        component[x] = component[component[x]];
        x = component[x];
    }
}

void merge(int a, int b){
    int u = find(a), v = find(b);
    if(u == v)
        return;
    size_comp[v] += size_comp[u];
    component[u] = component[v];
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        component[i] = i;
        size_comp[i] = 1;
    }
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << "0\n";
            continue;
        }
        if(find(a) == find(b)){
            if(max(size_comp[find(a)], size_comp[find(b)]) % 2 == 0)
                cout << a << "\n";
            else
                cout << b << "\n";
        }
        else{
            if(size_comp[find(a)] > size_comp[find(b)])
                cout << a << "\n";
            else if(size_comp[find(b)] > size_comp[find(a)])
                cout << b << "\n";
            else
                cout << "0\n";
        }
    }
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}