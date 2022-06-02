#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	long double ans = 0;
	for(int i = 0; i < n; ++i){	
		if(i + x > n) break;
		long long int sum = 0;
		for(int k = 0; k < x; ++k){
			sum += a[i];
			++i;
		}
		--i;
		// cout << sum << ' ';
		ans += (long double) sum / x;
	}
	cout << fixed << setprecision(9) << ans << '\n';
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
