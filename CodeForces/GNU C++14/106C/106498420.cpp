#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1000 + 2;
long long n, m, c, d, a[N], req[N], dough[N], profit[N], dp[15][N][110];

long long go(int i, int left, int stuf_remaining){
    if(i == m + 1)
        return 0;
    if(dp[i][left][stuf_remaining] != -1)
        return dp[i][left][stuf_remaining];
    long long ans = INT_MIN;
    if(i == 0){
        if(c + left <= n)
            ans = max(ans, go(i, left + c, stuf_remaining) + d);
        ans = max(ans, go(i + 1, left, a[i + 1]));
    }
    else{
        if(left + dough[i] <= n and stuf_remaining - req[i] >= 0)
            ans = max(ans, go(i, left + dough[i], stuf_remaining - req[i]) + profit[i]);
        ans = max(ans, go(i + 1, left, a[i + 1]));
    }
    return dp[i][left][stuf_remaining] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> c >> d;
    for(int i = 1; i <= m; ++i)
        cin >> a[i] >> req[i] >> dough[i] >> profit[i];
    cout << go(0, 0, 0) << "\n";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}