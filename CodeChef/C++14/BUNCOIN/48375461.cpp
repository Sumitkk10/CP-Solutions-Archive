#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
long long int n, q, a[N];

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(q--){
		long long int k, val;
		cin >> k >> val;
		a[k] = val;
		long long ans = 0, cur = 0;
		for(int j = 1; j <= n; ++j){
			cur += a[j];
			ans = max(ans, cur);
			if(cur < 0)
				cur =  0;
		}
		cout << ans << '\n';
	}
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}   