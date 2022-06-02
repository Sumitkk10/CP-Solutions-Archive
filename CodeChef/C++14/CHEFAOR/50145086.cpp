#include <iostream>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll int64_t
#define int int32_t
using namespace std;
const int N = 5003;
int or_query[N][N];
ll dp[2][N];

void compute(int l, int r, int tl, int tr, int cur){
    if(l > r)
        return;
    int mid = (l + r) >> 1;
    ll best = 0;
    int idx, ok = min(mid, tr + 1);
    for(int i = tl; i < ok; ++i){
        if(dp[cur ^ 1][i] + or_query[mid][i + 1] > best){
            best = dp[cur ^ 1][i] + or_query[mid][i + 1];
            idx = i;
        }
    }
    dp[cur][mid] = best;
    compute(l, mid - 1, tl, idx, cur);
    compute(mid + 1, r, idx, tr, cur);
}

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        or_query[i][i] = a[i];
        for(int j = i; j <= n; ++j)
            or_query[j][i] = (a[j] | or_query[j - 1][i]);
    }
    for(int i = 0; i <= n; ++i)
        dp[0][i] = dp[1][i] = 0;
    for(int j = 1; j <= k; ++j)
        compute(1, n, 0, n - 1, j & 1);
    cout << dp[k & 1][n] << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
