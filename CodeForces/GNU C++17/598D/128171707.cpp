#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 2;
const int MOD = 1e9 + 7;
int n, m, q, cur, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, cost[1000006], component[N][N], comp;
char a[N][N];
bool vis[N][N];

void dfs(int i, int j){
    vis[i][j] = true;
    component[i][j] = comp;
    for(int k = 0; k < 4; ++k){
        int ii = i + dx[k], jj = j + dy[k];
        if(ii < 1 or jj < 1 or ii > n or jj > m) continue;
        if(a[ii][jj] == '*'){ 
            ++cur;
            continue;
        }
        if(!vis[ii][jj])
            dfs(ii, jj);
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(vis[i][j] or a[i][j] == '*') continue;
            // cout << i << ' ' << j << endl;
            dfs(i, j);
            cost[comp] = cur;
            cur = 0;
            ++comp;
        }
    }
    while(q--){
        int i, j;
        cin >> i >> j;
        int x = component[i][j];
        cout << cost[x] << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
