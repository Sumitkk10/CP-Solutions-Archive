#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n + 1], ans[n + 1][n + 1];
    memset(ans, -1, sizeof ans);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        ans[i][i] = a[i];
        int x = i, y = i;
        for(int j = 1; j <= a[i] - 1 and x <= n; ++j){
            if(y > 1 and ans[x][y - 1] == -1) --y;
            else ++x;
            ans[x][y] = a[i];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
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
