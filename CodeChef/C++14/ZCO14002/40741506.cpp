#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n <= 2)
        cout << "0\n";
    int dp[n + 1] = {0};
    // dp[i] is the minimum time spent till ith day inc the ith day.
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    for(int i = 3; i < n; ++i)
        dp[i] = a[i] + min(dp[i - 1], min(dp[i - 3], dp[i - 2]));
    cout << min(dp[n - 1], min(dp[n - 3], dp[n - 2])) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}