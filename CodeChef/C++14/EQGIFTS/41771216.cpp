#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 152;
int n, dp[N][45002], all;
pair<int, int> a[N];

int go(int i, int sum){
    if(i == n)
        return abs(sum - (all - sum));
    if(dp[i][sum] != -1)
        return dp[i][sum];
    int ans = INT_MAX;
    ans = min(ans, go(i + 1, sum + a[i].first));
    ans = min(ans, go(i + 1, sum + a[i].second));
    return dp[i][sum] = ans;
}

int main(){
    fast;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        all += a[i].first + a[i].second;
    }
    cout << go(0, 0) << '\n';
    return 0;
}