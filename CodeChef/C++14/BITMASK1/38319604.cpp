#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll a[m], mn[n];
		for(int i = 0; i < n; ++i) 
			mn[i] = INT_MAX;
		for(int j = 0; j < n; ++j){
			for(int i = 0; i < m; ++i){
				cin >> a[i];
				mn[j] = min(mn[j], a[i]);
			}
		}
		cout << accumulate(mn, mn + n, 0) << "\n";
	}
	return 0;
}
