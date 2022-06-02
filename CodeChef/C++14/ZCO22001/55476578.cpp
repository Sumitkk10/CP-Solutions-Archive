#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define ld long double
#define F first
#define S second
using namespace std;
const int N  = 1e6 + 5, MOD = 1e9 + 7;
int n, m;

void solve(){
    cin >> n >> m;
    bool a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    int pre[n + 1][m + 1];
    memset(pre, 0, sizeof pre);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long sum = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        cout << (sum == ((x2 - x1 + 1) * (y2 - y1 + 1)) ? "1\n" : "0\n");
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