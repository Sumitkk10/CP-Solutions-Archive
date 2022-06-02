#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1000000009; 
const int N = 1e6 + 1;

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

int main(){
    vector<ll> dp(N);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i < N; ++i)
        dp[i] = add(dp[i-2], dp[i-3]);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}