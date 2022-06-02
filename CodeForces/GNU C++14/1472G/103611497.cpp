#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int d[N + 1], n, m, dp[N][2];
vector<int> graph[N];

int go(int node, bool k){
    if(dp[node][k] < INT_MAX)
        return dp[node][k];
    int ans = d[node];
    for(auto e : graph[node]){
        if(d[e] <= d[node]){
            if(k == 1) continue;
            ans = min(ans, go(e, 1));
        }
        else
            ans = min(ans, go(e, k));
    }
    return dp[node][k] = ans;
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i){
        d[i] = INT_MAX;
        dp[i][0] = dp[i][1] = INT_MAX;
    }
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto e : graph[u]){
            if(d[e] > d[u] + 1){
                d[e] = d[u] + 1;
                q.push(e);
            }
        }
    }
    go(1, 0);
    for(int i = 1; i <= n; ++i)
        cout << min(dp[i][0], dp[i][1]) << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i)
        graph[i].clear();
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
