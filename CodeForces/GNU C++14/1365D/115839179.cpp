#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 50 + 5;
const int MOD = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[N][N];

void solve(){
    int n, m, ct = 0;
    cin >> n >> m;
    char a[n + 1][m + 1];
    vector<pair<int, int> > v;
    queue<pair<int, int> > q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if(a[i][j] == 'G')
                ++ct;
            if(a[i][j] == 'B')
                v.push_back({i, j});
        }
    }
    for(auto k : v){
        if(a[k.first][k.second + 1] == '.' and k.second + 1 <= m and (k.first != n or k.second + 1 != m)) a[k.first][k.second + 1] = '#';
        if(a[k.first][k.second - 1] == '.' and k.second - 1 >= 1 and (k.first != n or k.second - 1 != m)) a[k.first][k.second - 1] = '#';
        if(a[k.first + 1][k.second] == '.' and k.first + 1 <= n and (k.first + 1 != n or k.second != m)) a[k.first + 1][k.second] = '#';
        if(a[k.first - 1][k.second] == '.' and k.first + 1 >= 1 and (k.first - 1 != n or k.second != m)) a[k.first - 1][k.second] = '#';
    }
    if(ct == 0){
        cout << "Yes\n";
        return;
    }
    q.push({n, m});
    memset(vis, 0, sizeof vis);
    vis[n][m] = true;
    while(!q.empty()){
        int i = q.front().first , j = q.front().second;
        q.pop();
        for(int x = 0; x < 4; ++x){
            int cur = i + dx[x];
            int cur1 = j + dy[x];
            if(cur < 1 or cur1 < 1 or cur > n or cur1 > m) continue;
            if(!vis[cur][cur1] and a[cur][cur1] != '#'){ 
                q.push({cur, cur1});
                vis[cur][cur1] = true;
            }
        }
    }
    bool ok = true;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == 'G' and !vis[i][j]) ok = false;
            if(a[i][j] == 'B' and vis[i][j]) ok = false;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
