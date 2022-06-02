#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
int n, m1, m2;
int parent[N], parent1[N];

int find(int a){
    while(1){
        if(a == parent[a]) return a;
        else{
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
    }
}

void merge(int u, int v){
    int a = find(u), b = find(v);
    if(a == b) return;
    parent[a] = b;
}

int find1(int a){
    while(1){
        if(a == parent1[a]) return a;
        else{
            parent1[a] = parent1[parent1[a]];
            a = parent1[a];
        }
    }
}

void merge1(int u, int v){
    int a = find1(u), b = find1(v);
    if(a == b) return;
    parent1[a] = b;
}

void solve(){
    map<pair<int, int>, bool> mp;
    cin >> n >> m1 >> m2;
    for(int i = 1; i <= n; ++i)
        parent1[i] = parent[i] = i;
    for(int i = 1; i <= m1; ++i){
        int u, v;
        cin >> u >> v;
        merge(u, v);
        mp[{u, v}] = true;
        mp[{v, u}] = true;
    }
    for(int i = 1; i <= m2; ++i){
        int u, v;
        cin >> u >> v;
        merge1(u, v);
        mp[{u, v}] = true;
        mp[{v, u}] = true;
    }
    vector<pair<int, int> > v;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(mp[{i, j}]) continue;
            if(find(i) == find(j)) continue;
            if(find1(i) == find1(j)) continue;
            merge(i, j);
            merge1(i, j);
            v.push_back({i, j});        
        }
    }
    cout << v.size() << "\n";
    for(auto k : v)
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
