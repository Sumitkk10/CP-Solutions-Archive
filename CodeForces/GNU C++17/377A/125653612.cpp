#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500+ 5;
const int MOD = 1e9 + 7;
int n, m, k, s, cnt = 0, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char a[N][N];
bool vis[N][N];

void dfs(int i, int j){
    if(cnt >= s - k) return;
    ++cnt;
    vis[i][j] = true;
    for(int u = 0; u < 4; ++u){
        int cur_i = i + dx[u], cur_j = j + dy[u];
        if(cur_i < 1 or cur_j < 1 or cur_i > n or cur_j > m) continue;
        if(vis[cur_i][cur_j]) continue;
        dfs(cur_i, cur_j);
    }
}

void solve(){
    cin >> n >> m >> k;
    pair<int, int> str;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            vis[i][j] = (a[i][j] == '#');
            if(a[i][j] != '#'){
                str.first = i;
                str.second = j;
                ++s;
            }
        }
    }
    dfs(str.first, str.second);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(vis[i][j]) cout << a[i][j];
            else cout << "X";
        }
        cout << "\n";
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
