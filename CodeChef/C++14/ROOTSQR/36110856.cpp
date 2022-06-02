#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
	fast;
	ll t, x;
	cin >> t >> x;
	while(t--){
		ll n;
		cin >> n;
		if(n < 0){
			cout << "no\n" ;
			continue;
		} 
		ll sq = sqrt(n);
		ll ans = n - (sq*sq);
		if(ans <= (0.01*x*n)) cout << "yes\n";
		else cout << "no\n";
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}