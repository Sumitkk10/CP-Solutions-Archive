#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 2;
const int MOD = 1e9 + 7;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	long long xorr = 0;
	xorr = (k + 2);
	for(int i = 2; i <= m; ++i){
		if((min(n, i) % 2) == 0)
			continue;
		xorr = (xorr ^ (k + 1 + i));
	}
	for(int i = 2; i <= n; ++i){
		if((min(n - i + 1, m) % 2) == 0)
			continue;
		xorr = (xorr ^ (k + m + i));
	}
	cout << xorr << "\n";
}

int main(){
	fast;
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
