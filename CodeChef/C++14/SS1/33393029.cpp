#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
ll add(ll a, ll b){
    return ((a % MOD + b % MOD) % MOD);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[k], dp[n];
        for(int i = 0; i < n; ++i)
            dp[i] = -1;
        for(int i = 0; i < k; ++i){
            cin >> a[i];
            dp[a[i]-1] = 0;
        }
        if(dp[0] == -1) 
            dp[0] = 1;
        if(dp[1] == -1) 
            dp[1] = dp[0] + 1;
        if(dp[2] == -1) 
            dp[2] = dp[1] + dp[0] + 1;
        for(int i = 3; i < n; ++i){
            if(dp[i] == -1)
                dp[i] = add(dp[i-1], add(dp[i-2], dp[i-3]));
        }
        cout << dp[n-1] << '\n';
    }
    return 0;
}