#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(k == 1)
		cout << *min_element(a, a + n) << '\n';
	else if(k > 2 or n == k)
		cout << *max_element(a, a + n) << '\n';
	else{
		long long int mn = LLONG_MAX, ans = -LLONG_MAX;
		for(int i = 0; i < n; ++i){
			mn = min(mn, a[i]);
			ans = max(ans, mn);
		}
		mn = LLONG_MAX;
		for(int i = n - 1; i >= 0; --i){
			mn = min(mn, a[i]);
			ans = max(ans, mn);
		}
		cout << ans << '\n';
	}
	return 0;
}
