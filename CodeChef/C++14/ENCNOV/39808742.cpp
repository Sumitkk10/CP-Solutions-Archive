#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 72;
const int MOD = 1e9 + 7;

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	// there can be only l to r distinct elements in my array.
	// Min value which my array can have is 1.
	// Max value which my array can have is 2^(n - 1).
	long long int ans = (n - l) + 1, pre = 2;
	for(int i = n - l + 1; i < n; ++i){
		ans += pre;
		pre *= 2;
	}
	cout << ans << ' ';
	pre = 1;
	ans = 0;
	for(int i = 0; i < r; ++i){
		ans += pre;
		pre *= 2;
	}
	pre /= 2;
	for(int i = r; i < n; ++i)
		ans += pre;
	cout << ans << "\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}