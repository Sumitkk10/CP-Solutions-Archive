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
		ll n;
		cin >> n;
		ll b[n + 1];
		for(int i = 1; i <= n; ++i) cin >> b[i];
		bool ok = true;
		for(int i = 1; i <= n; ++i){
			if(b[i] == i) continue;
			else{
				if(__gcd((ll) i, b[i]) != b[i]){
					ok = false;
					break;
				}
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
