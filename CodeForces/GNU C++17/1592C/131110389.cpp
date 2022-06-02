#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[N];
long long n, k, a[N], cnt, tot, subtree[N];

void clr(){
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
}

int dfs(int node, int p){
    subtree[node] = a[node];
    for(auto k : graph[node])
        if(k != p)
            subtree[node] = (subtree[node] ^ dfs(k, node));
    if(subtree[node] == tot){
        ++cnt;
        return 0;
    }
    else
        return subtree[node];
}

void solve(){
    cin >> n >> k;
    tot = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        tot ^= a[i];
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(!tot){
        cout << "YES\n";
        clr();
        return;
    }
    if(k == 2){
        cout << "NO\n";
        clr();
        return;
    }
    cnt = 0;
    dfs(1, 0);
    cout << (cnt >= 2 ? "YES\n" : "NO\n");
    clr();
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
