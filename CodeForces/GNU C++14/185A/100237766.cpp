#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}

int main(){
	fast;
	long long int n;
	cin >> n;
	long long int x = power(2, n);
	long long int ans = (x * (x + 1));
	ans /= 2;
	cout << ans % MOD << '\n';
	return 0;
}
