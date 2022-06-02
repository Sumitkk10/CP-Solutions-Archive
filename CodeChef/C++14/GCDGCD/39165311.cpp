#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		mp[a[i]]++;
	}
	int ans = 0;
	for(auto k : mp)
		ans = max(ans, k.second);
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
