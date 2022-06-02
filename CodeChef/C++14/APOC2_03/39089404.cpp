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
	sort(a, a + n);
	ll ans = LLONG_MAX;
	ans = min(ans, abs(a[0] - a[k - 1]));
	for(int i = 1; i <= n - k; ++i)
		ans = min(ans, abs(a[i] - a[i + k - 1]));
	cout << ans << "\n";
	return 0;
}
