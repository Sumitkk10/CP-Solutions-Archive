#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e4 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	long long int a[n + 1];
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long int ans = accumulate(a + 1, a + n + 1, 0);
	int q;
	cin >> q;
	while(q--){
		long long int a, b, c;
		cin >> a >> b >> c;
		ans += (b - a + 1) * c; 
	}
	cout << ans << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
