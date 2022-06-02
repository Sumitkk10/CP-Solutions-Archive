#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 10 + 5;
const int MOD = 1e9 + 7;
int n, m;
char a[N][N];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    int ans = 0, ans1 = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i % 2 == 0 and j % 2 == 0 and a[i][j] != '*') ++ans;
            if(i % 2 == 0 and j % 2 and a[i][j] != '.') ++ans;
            if(i % 2 and j % 2 and a[i][j] != '*') ++ans;
            if(i % 2 and j % 2 == 0 and a[i][j] != '.') ++ans;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i % 2 == 0 and j % 2 and a[i][j] != '*')
                ++ans1;
            if(i % 2 == 0 and j % 2 == 0 and a[i][j] != '.')
                ++ans1;
            if(i % 2 and j % 2 == 0 and a[i][j] != '*')
                ++ans1;
            if(i % 2 and j % 2 and a[i][j] != '.') 
                ++ans1;
        }
    }
    if((n * m) % 2)
        cout << ans << '\n';
    else
        cout << min(ans, ans1) << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}