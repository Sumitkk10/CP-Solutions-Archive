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
		ll n, k, x, y;
		cin >> n >> k >> x >> y;
		bool ok = true;
		for(int i = 0; i <= n; ++i){
			if((x + (k * i)) % n == y){
				cout << "YES\n";
				ok = false;
				break;
			}
		}
		if(ok) cout << "NO\n";
	}
	return 0;
}
