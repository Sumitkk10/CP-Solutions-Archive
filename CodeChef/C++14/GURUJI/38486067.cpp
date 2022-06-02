#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t = 1;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n == 2){
			cout << "2\n";
			continue;
		}
		ll ans = 0;
		while(n > 1){
			n = (n + 1) / 2;
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
