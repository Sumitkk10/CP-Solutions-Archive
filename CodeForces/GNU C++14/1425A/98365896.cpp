#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e7;
const int MOD = 1e9 + 7;

void solve() {
	long long int n;
	cin >> n;
	long long int ans = 0, chance = 0;
	while (n) {
		if (!chance) {
			chance = 1;
			if (!(n % 2) && ((n/2)%2 || n/2 == 2)) {
				ans += n / 2;
				n /= 2;
			}
			else {
				++ans;
				--n;
			}
		}
		else {
			if (!(n % 2) && ((n/2)%2 || n/2 == 2)) n /= 2;
			else --n;
			chance = 0;
		}
	}
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
