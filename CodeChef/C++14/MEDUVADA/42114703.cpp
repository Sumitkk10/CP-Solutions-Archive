#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define pb push_back
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;
bool vis[N][N];
pair<int, int> par[N][N];

int main(){
    fast;
    int n, m;
    cin >> n >> m;
    char a[n][m];
    pair<int, int> str, endd;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 'M')
                str.first = i, str.second = j;
            if(a[i][j] == 'D')
                endd.first = i, endd.second = j;
        }
    }
    queue<pair<int, int> > q;
    q.push({str.first, str.second});
    vis[str.first][str.second] = true;
    par[str.first][str.second] = {-1, -1};
    bool ok = 0;
    while(!q.empty()){
        int i = q.front().first, j = q.front().second;
        q.pop();
        if(i == endd.first and j == endd.second){
            ok = 1;
            break;
        }
        if(i + 1 < n and a[i + 1][j] != '#' and !vis[i + 1][j]){
            q.push({i + 1, j});
            vis[i + 1][j] = true;
            par[i + 1][j] = {i, j};
        }
        if(j + 1 < m and a[i][j + 1] != '#' and !vis[i][j + 1]){
            q.push({i, j + 1});
            vis[i][j + 1] = true;
            par[i][j + 1] = {i, j};
        }
        if(i - 1 >= 0 and a[i - 1][j] != '#' and !vis[i - 1][j]){
            q.push({i - 1, j});
            vis[i - 1][j] = true;
            par[i - 1][j] = {i, j};
        }
        if(j - 1 >= 0 and a[i][j - 1] != '#' and !vis[i][j - 1]){
            q.push({i, j - 1});
            vis[i][j - 1] = true;
            par[i][j - 1] = {i, j};
        }
        if(i == 0 and a[n - 1][j] != '#' and !vis[n - 1][j]){
            q.push({n - 1, j});
            vis[n - 1][j] = true;
            par[n - 1][j] = {i, j};
        }
        if(i == n - 1 and a[0][j] != '#' and !vis[0][j]){
            q.push({0, j});
            vis[0][j] = true;
            par[0][j] = {i, j};
        }
        if(j == 0 and a[i][m - 1] != '#' and !vis[i][m - 1]){
            q.push({i, m - 1});
            vis[i][m - 1] = true;
            par[i][m - 1] = {i, j};
        }
        if(j == m - 1 and a[i][0] != '#' and !vis[i][0]){
            q.push({i, 0});
            vis[i][0] = true;
            par[i][0] = {i, j};
        }
    }
    if(!ok){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int i = par[endd.first][endd.second].first, j = par[endd.first][endd.second].second;
    while(par[i][j].first != -1){
        a[i][j] = 'x';
        int x = i, y = j;
        i = par[x][y].first, j = par[x][y].second;
    }
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j];
        cout << "\n";
    }
    return 0;
}