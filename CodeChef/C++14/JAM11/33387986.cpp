#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1000000007;
ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1)
            cout << 1 << '\n';
        else if(n == 2)
            cout << 2 << '\n';
        else if(n == 3)
            cout << 4 << '\n';
        else{
            ll dp[n];
            dp[0] = 1;
            dp[1] = 2;
            dp[2] = 4;
            for(int i = 3; i < n; ++i)
                dp[i] = add(dp[i-1], add(dp[i-2],dp[i-3]));
            cout << dp[n-1] << '\n';
        }
    }
    return 0;
}