#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

void solve(){
	int n;
	cin >> n;
	int a[2 * n];
	for(int i = 0; i < n+n; ++i)
		cin >> a[i];
	sort(a, a + 2*n, greater<int>());
	bool ok = true;
	for(int i = 0; i < n; ++i){
		int ct = 0;
		for(int j = n; j < 2*n; ++j){
			if(a[i] > a[j])
				++ct;
		}
		if(ct != n){
			ok = 0;
			break;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main() {
	fast;
	int t = 1;
     // cin >> t;
	while(t--)
		solve();
}