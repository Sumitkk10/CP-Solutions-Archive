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
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long int dp[n + 1] = {0}, ans = a[n - 1];
    dp[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; --i){
    	dp[i] = a[i];
    	if(i + a[i] < n)
    		dp[i] += dp[i + a[i]];
    	ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
