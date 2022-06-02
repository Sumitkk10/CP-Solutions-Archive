#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 400 + 5;
const int MOD = 1e9 + 7;
int n, k, a[N], dp[N][N][N][2];

long long int go(int i, int left, int pre, int buy){
    if(left < 0)
        return INT_MIN;
    if(i == n)
        return 0;
    if(dp[i][left][pre][buy] != -1)
        return dp[i][left][pre][buy];
    long long int ans = INT_MIN;
    if(buy == 0)
        ans = max(ans, go(i + 1, left - 1, i, 1));
    else
        ans = max(ans, go(i + 1, left - 1, i, 0) + a[i] - a[pre]);
    ans = max(ans, go(i + 1, left, pre, buy));
    return dp[i][left][pre][buy] = ans;
}

int main() {
    fast;
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << go(0, k, 0, 0) << '\n';
    return 0;
}
