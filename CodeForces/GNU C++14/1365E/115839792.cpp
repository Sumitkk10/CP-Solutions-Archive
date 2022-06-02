#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 4e4 + 5;
long long int n, a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			for(int k = j; k <= n; ++k){
				ans = max(ans, (a[i] | a[j]) | a[k]);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
}