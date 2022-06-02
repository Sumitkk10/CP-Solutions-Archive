#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 2e4 + 5;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k; 
	int a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	long long int ans = 0, mx = INT_MIN;
	for(int i = 0; i < k; ++i)
		ans += a[i];
	mx = max(mx, ans);
	for(int i = 1; i <= n - k; ++i){
		ans -= a[i - 1];
		ans += a[i + k - 1];
		mx = max(mx, ans);
	}
	cout << mx << '\n';
}

int main(){
	fast;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
