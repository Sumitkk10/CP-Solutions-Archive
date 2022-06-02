#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, d, a[N], b[N];

void solve(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<bool> vis(n + 1, 0);
    queue<pair<int, int> > q;
    for(int i = 0; i < n; ++i){
        if(a[i] == 0){
            q.push({i, 0});
            vis[i] = true;
        }
    }
    int ans = 0;
    while(!q.empty()){
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();
        int to = (node + d) % n;
        if(vis[to]) continue;
        ans = max(ans, cost + 1);
        q.push({to, cost + 1});
        vis[to] = 1;
    }
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            cout << "-1\n";
            return;
        }
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
