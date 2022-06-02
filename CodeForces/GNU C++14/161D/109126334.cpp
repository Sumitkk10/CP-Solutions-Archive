#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 50001;
const int MOD = 1e9 + 7;
vector<int> graph[N];
long long int n, k, in[N][501], out1[N][501];

void dfs(int source, int p){
    for(auto k : graph[source])
        if(k != p)
            dfs(k, source);
    in[source][0] = 1;
    for(int i = 1; i <= k; ++i){
        long long int ans = 0;
        for(auto k : graph[source])
            if(k != p)
                ans += in[k][i - 1];
        in[source][i] = ans;
    }
}

void dfs1(int source, int p){
    for(auto k : graph[source])
        if(k != p)
            dfs1(k, source);
    for(int i = 2; i <= k; ++i){
        long long sum = 0;
        for(auto k : graph[source])
            if(k != p)
                sum += in[k][i - 2];
        for(auto k : graph[source]){
            if(k != p){
                sum -= in[k][i - 2];
                out1[k][i] += sum;
            }
        }
    }
}

void dfs2(int source, int p){
    out1[source][0] += 1;
    for(int i = 1; i <= k; ++i){
        long long int ans = 0;
        for(auto k : graph[source])
            if(k == p)
                ans += out1[k][i - 1];
        out1[source][i] += ans;
    }
    for(auto k : graph[source])
        if(k != p)
            dfs2(k, source);
}

int main(){
    fast;
    cin >> n >> k;
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    dfs1(1, -1);
    dfs2(1, -1);
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += out1[i][k];
    cout << ans << "\n";
    return 0;
}
