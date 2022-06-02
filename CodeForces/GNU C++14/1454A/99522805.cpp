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
	vector<int> ans;
	for (int i = n; i >= 1; --i)
		ans.push_back(i);
	if (n % 2)
		swap(ans[n / 2], ans[0]);
	for (auto k : ans)
		cout << k << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}