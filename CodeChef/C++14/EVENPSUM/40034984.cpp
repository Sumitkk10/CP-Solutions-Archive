#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	long long int a, b;
	cin >> a >> b;
	long long int even = a / 2, even1 = b / 2;
	long long int ans = even * even1;
	long long int odd = (a + 1) / 2, odd1 = (b + 1) / 2;
	cout << ans + (odd * odd1) << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
