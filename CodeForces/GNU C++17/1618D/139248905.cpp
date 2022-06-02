#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long long ans = 0;
	for(int i = 0; i < (n - 2*k); ++i)
		ans += a[i];
	int mx = 0;
	map<int, int> mp;
	for(int i = n - 2*k; i < n; ++i){
		mp[a[i]]++;
		mx = max(mx, mp[a[i]]);
	}
	cout << ans + max(0, (mx - (2*k - mx)) / 2) << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
