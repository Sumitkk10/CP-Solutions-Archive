#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e6 + 3;
ll fac[N];
vii prime;

void sieve(){
	for(int i = 1; i < N; ++i){
		for(int j = i; j < N; j += i)
			fac[j]++;
		if(fac[i] == 2) prime.pb(i);
	}
}

int main(){
	fast;
	ll t; cin >> t;
	sieve();
	while(t--){
		ll n; cin >> n;
		ll ans = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
		if(ans == 0) cout << prime[ans] << "\n";
		else if(abs(prime[ans] - n) < abs(prime[ans - 1] - n)) cout << prime[ans] << "\n";
		else cout << prime[ans - 1] << "\n";
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}