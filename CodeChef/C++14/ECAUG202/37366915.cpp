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
		ll n; cin >> n;
		ll a[n],sum=0;
		for(int i = 0; i < n; ++i){
			cin >> a[i];
			if((a[i] & 1) == 0)
				sum += a[i];
		}
		cout << sum << "\n";
	}
	return 0;
}
