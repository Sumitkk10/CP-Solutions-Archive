#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve() {
    int n, m, k;

    cin >> n >> m >> k;

    int a[n + 1][m + 1];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];

    long long int pre_sum[n + 1][m + 1];

    vector<vector<vector<long long int> > > mx_dp(n + 5, vector<vector<long long int> >(m + 1, vector<long long int>(k + 1)));
    vector<vector<vector<long long int> > > mn_dp(n + 5, vector<vector<long long int> >(m + 1, vector<long long int>(k + 1)));

    memset(pre_sum, 0, sizeof pre_sum);

    for(int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            pre_sum[i][j] = pre_sum[i][j - 1] + a[i][j];

    // mn_dp[i][j][k] stores the min sum to come to (i, j) with at most k up-left moves;
    // mx_dp[i][j][k] stores the max sum to come to (i, j) with at most k up-left moves;

    for(int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            mx_dp[i][j][0] = mx_dp[i - 1][j][0] + pre_sum[i][j];
            mn_dp[i][j][0] = mn_dp[i - 1][j][0] + pre_sum[i][j - 1];
        }
    }

    for(int i = 1; i <= n; ++i){

        for(int j = 1; j <= m; ++j){

            for(int move = 1; move <= k; ++move){

                mx_dp[i][j][move] = max(mx_dp[i - 1][j][move], mx_dp[i - 1][j - 1][move - 1]) + pre_sum[i][j];
                mn_dp[i][j][move] = min(mn_dp[i - 1][j][move], mn_dp[i - 1][j - 1][move - 1]) + pre_sum[i][j - 1];

            }

        }

    }

    long long ans = INT_MIN;

    for(int i = 1; i <= m; ++i)
        for(int j = i + k + 1; j <= m; ++j)
            ans = max(ans, mx_dp[n][j][k] - mn_dp[n][i][k]);

    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
/*
1
7 8 3
2 1 1 1 -1 -1 -1 -1
2 1 1 1 -1 -1 -1 -1
-1 1 1 1 -1 -1 -1 -1
-1 1 1 1 -1 -1 -1 -1
-1 1 1 1 1 -1 -1 -1
-1 -1 1 1 1 1 -1 -1
-1 -1 1 1 1 1 1 -1
 */