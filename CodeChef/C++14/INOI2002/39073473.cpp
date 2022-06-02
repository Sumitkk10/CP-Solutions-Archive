#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;
ll dp[N];

ll add(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

ll tiles(ll n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll ways = 0;
    ways = add(ways, tiles(n - 2));
    ways = add(ways, tiles(n - 3));
    return dp[n] = ways;
}

ll tiles1(ll n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll way = 0;
    way = add(way, tiles1(n - 1));
    way = add(way, tiles1(n - 3));
    way = add(way, mul(2, tiles1(n-6)));
    return dp[n] = way;
}

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll k, n;
        cin >> k >> n;
        memset(dp, -1, sizeof(dp));
        if(k == 1){
            if(n%3 == 0) cout << "1\n";
            else cout << "0\n";
        }
        else if(k == 2)
            cout << tiles(n) << "\n";
        else{
        	ll f[n + 2] = {0}, g[n + 2] = {0}, h[n + 2] = {0};
        	f[1] = f[2] = 1;
        	f[3] = 2;
        	g[1] = g[2] = 0;
        	g[3] = 1;
        	h[1] = 0;
        	h[2] = h[3] = 1;
        	for(int i = 4; i <= n; ++i){
        		f[i] = add(f[i - 1], add(f[i - 3], mul(2, g[i - 3])));
        		h[i] = add(h[i - 3], f[i - 2]);
        		g[i] = add(h[i - 1], g[i - 3]); 
        	}
        	cout << f[n] << "\n";
        }
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}