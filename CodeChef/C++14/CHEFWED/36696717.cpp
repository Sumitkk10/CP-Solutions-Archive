#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1005;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		ll go[n + 1][n + 1], family[n];
		map<ll, ll> freq;
		for(int i = 0; i < n; ++i) cin >> family[i];
		memset(go, 0, sizeof(go));
		for(ll i = 0; i < n; ++i){
			freq.clear();
			for(ll j = i; j < n; ++j){
				if(j == 0) go[i][j] = 0;
				else go[i][j] = go[i][j-1];
				if(freq.count(family[j])){
					if(freq[family[j]] == 1) ++go[i][j];
					++go[i][j];
				}
				++freq[family[j]];
			}
		}
		ll ans[105][1005], mn = 1e17;
		memset(ans, 0, sizeof(ans));
		for(ll i = 1; i <= n; ++i) ans[1][i] = go[0][i - 1];
		for(ll i = 2; i <= 100; ++i) ans[i][1] = 0;
		for(ll i = 2; i <= 100; ++i){
			for(ll j = 2; j <= n; ++j){
				ll mnn = 1e17;
				for(ll jj = 1; jj < j; ++jj)
					mnn = min(mnn, ans[i - 1][jj] + go[jj][j - 1]);
				ans[i][j] = mnn;
			}
		}
		for(ll i = 1; i <= 100; ++i)
			mn = min(mn, (i*k)+ans[i][n]);
		cout << mn << "\n";
		freq.clear();

	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
