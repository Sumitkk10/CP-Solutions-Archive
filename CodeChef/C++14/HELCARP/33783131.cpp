#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007, N = 8003, M = 63;
ll n, k, dp[N][M], a[N], b[M]; 
ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll go(ll n, ll idx){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(idx == k) return 0;
    if(dp[n][idx] != -1) return dp[n][idx];
    int ans = 0;
    for(int i = 0; i <= b[idx]; i++){
        ans = add(ans, go(n - (a[idx] * i), idx + 1));
    }
    return dp[n][idx] = ans;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < k; ++i)
            cin >> a[i];
        for(int i = 0; i < k; ++i)
            cin >> b[i];
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                dp[i][j] = -1;
        cout << go(n, 0) << '\n';
    }     
    return 0;
}