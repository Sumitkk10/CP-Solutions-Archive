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
		ll n, m, s;
		cin >> n >> m >> s;
		m--;
		s += m;
		if(s < n) cout << s % n << "\n";
		else if(s % n == 0) cout << n << "\n";
		else 
			cout << (s % n) << "\n";
	}
	return 0;
}