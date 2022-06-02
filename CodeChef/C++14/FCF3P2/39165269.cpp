#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	long long int k;
	cin >> n >> k;
	int a[n];
	long long int sum = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		sum = (sum + a[i]) % MOD;
	}
	if((k / n) != 0)
		sum = (sum * (k / n)) % MOD;
	else
		sum = 0;
	int j = k % n;
	for(int i = 0; i < j; ++i)
		sum = (sum + a[i]) % MOD;
	cout << sum << "\n";
}

int main() {
	fast;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
