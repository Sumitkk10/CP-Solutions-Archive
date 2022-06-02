#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ld l, r;
		cin >> l >> r;
		ld ans = r - l + 1;
		ll k = r/7;
		ll kk = (l-1)/7;
		k = k - kk;
		cout << fixed << setprecision(6) << (ld) k/ans << "\n";
	}
	return 0;
}
