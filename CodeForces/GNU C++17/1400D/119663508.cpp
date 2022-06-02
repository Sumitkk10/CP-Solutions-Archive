#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 3003;
ll pre_hash[N][N], suf_hash[N][N];

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n; 
		cin >> n;
		ll a[n];
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= n; ++j){
				pre_hash[i][j] = 0;
				suf_hash[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i) 
			cin >> a[i];
		map<int, int> mp, mpp;
		for(int i = 0; i < n; ++i){
			mp[a[i]]++;
			pre_hash[i][a[i]] = mp[a[i]];
          	for(int j = i + 1; j < n; ++j) pre_hash[j][a[i]] = mp[a[i]];
		}
		for(int i = n - 1; i >= 0; --i){
			mpp[a[i]]++;
			suf_hash[i][a[i]] = mpp[a[i]];
          	for(int j = i - 1; j >= 0; --j) suf_hash[j][a[i]] = mpp[a[i]];
		}
		ll ans = 0;
		for(int i = 1; i < n - 2; ++i){
			for(int j = n - 2; j > i; --j){
              	// cout << a[i] << " " << a[j] << " " << pre_hash[i - 1][a[j]] * suf_hash[j + 1][a[i]] << endl;
				ans += (pre_hash[i - 1][a[j]] * suf_hash[j + 1][a[i]]);
			}
		}
		cout << ans << "\n";
		for(int i = 0; i <= n; ++i) 
			for(int j = 0; j <= n; ++j) 
				pre_hash[i][j] = 0, suf_hash[i][j] = 0;
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}