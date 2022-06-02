#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
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
        if(mp[{i, 1}]) continue;
        if(find(i) == find(1)) continue;
        if(find1(i) == find1(1)) continue;
        merge(i, 1);
        merge1(i, 1);
        v.push_back({i, 1});
    }
    int l = 2, r = 2;
    while(l <= n and r <= n){
        while(l <= n and find(l) == find(1)) ++l;
        while(r <= n and find1(r) == find1(1)) ++r;
        if(l > n or r > n) break;
        merge(l, r);
        merge1(l, r);
        v.push_back({l, r});
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
