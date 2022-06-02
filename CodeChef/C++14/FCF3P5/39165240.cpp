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
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int i = 0, j = n - 1;
	bool ok = 0;
	while(i <= j && i < n && j > 0){
		if(i == j) ok = 1;
		i += a[i];
		j -= a[j];
	}
	cout << (ok ? "Yes\n" : "No\n");
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
