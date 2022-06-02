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
		ll j = 1, ans = 0;
		while(j <= n){
			j *= 2;
			++ans;
		}
		if(n == 1) --ans;
		cout << ans << "\n";
	}
	return 0;
}