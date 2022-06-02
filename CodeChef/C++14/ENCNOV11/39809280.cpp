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
	int ans = sqrt(n);
	ans -= ans/3;
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}