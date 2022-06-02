#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 72;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	int i = 0, j = n - 1;
	while (a[i] == b[i] && i < n)
		++i;
	while (a[j] == b[j] and j >= 0)
		--j;
	cout << max(0, j - i + 1) << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}