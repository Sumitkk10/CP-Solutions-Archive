#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    if(n < k) cout << 1;
    else{
        ll dp[n];
        for(int i = 0; i < k; ++i) dp[i] = 1;
        int sum = k;
        for(int i = k; i < n; ++i){
            dp[i] = sum;
            sum = (sum + dp[i]) % MOD;
            sum = (sum - dp[i-k]) % MOD;
        }
        cout << dp[n-1];
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}