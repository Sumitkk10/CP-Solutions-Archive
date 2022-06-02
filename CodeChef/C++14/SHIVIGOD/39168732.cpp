#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500;
const int MOD = 1e9 + 7;
ll n;

ll max_sum(ld a[], int how_many) {
	ll sum = 0;
	for (int i = 0; i < how_many; ++i)
		sum += a[i];
	ll ans = sum;
	for (int i = 1; i <= n - how_many; ++i) {
		sum -= a[i - 1];
		sum += a[i + how_many - 1];
		ans = max(ans, sum);
	}
	return ans;
}

void solve() {
	int l, r;
	cin >> n >> r >> l;
	ld a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ld mx = 0;
	for (int i = l; i <= r; ++i) {
		ll sum = max_sum(a, i);
		mx = max(mx, (ld) ((ld) (sum * 1.0) / (ld) i * 1.0));
	} 
	cout << fixed << setprecision(7) << mx << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
