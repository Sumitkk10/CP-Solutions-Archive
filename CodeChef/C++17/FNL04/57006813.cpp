#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL) 
#define ll int
#define pb push_back
#define F first 
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
 
void solve(){
    cin >> n >> m;
    long long a[n + 1][m + 1], dis[n + 1][m + 1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            dis[i][j] = LLONG_MAX;
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    priority_queue<pair<long long, pair<int, int> >, vector<pair<long long, pair<int, int> > >, greater<pair<long long, pair<int, int> > > > pq;
    dis[x1][y1] = 0;
    pq.push({0, {x1, y1}});
    while(!pq.empty()){
        pair<long long, pair<int, int> > cur = pq.top();
        pq.pop();
                if(cur.F != dis[cur.S.F][cur.S.S]) continue;
        if(cur.S.S == 1){
            if(dis[cur.S.F][m] > cur.F + a[cur.S.F][m]){
                dis[cur.S.F][m] = cur.F + a[cur.S.F][m];
                pq.push({dis[cur.S.F][m], {cur.S.F, m}});
            }
        }
        if(cur.S.S == m){
            if(dis[cur.S.F][1] > cur.F + a[cur.S.F][1]){
                dis[cur.S.F][1] = cur.F + a[cur.S.F][1];
                pq.push({dis[cur.S.F][1], {cur.S.F, 1}});
            }
        }
        if(cur.S.F == 1){
            if(dis[n][cur.S.S] > cur.F + a[n][cur.S.S]){
                dis[n][cur.S.S] = cur.F + a[n][cur.S.S];
                pq.push({dis[n][cur.S.S], {n, cur.S.S}});
            }
        }
        if(cur.S.F == n){
            if(dis[1][cur.S.S] > cur.F + a[1][cur.S.S]){
                dis[1][cur.S.S] = cur.F + a[1][cur.S.S];
                pq.push({dis[1][cur.S.S], {1, cur.S.S}});
            }
        }
        for(int i = 0; i < 4; ++i){
            int x = cur.S.F + dx[i], y = cur.S.S + dy[i];
            if(x > 0 and y > 0 and x <= n and y <= m and dis[x][y] > cur.F + a[x][y]){
                dis[x][y] = cur.F + a[x][y];
                pq.push({dis[x][y], {x, y}});
            }
        }
    }
    cout << dis[x2][y2] << '\n';
}
 
int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}