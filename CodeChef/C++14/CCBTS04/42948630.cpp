#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void solve(){
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first;
    for(int i = 0; i < n; ++i)
        cin >> a[i].second;
    int dp[n + 1], ans = 1;
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j)
            if(a[j].first < a[i].first and a[j].second > a[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
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
