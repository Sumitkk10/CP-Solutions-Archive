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
		ll a[n];
		for(int i = 0; i < n; ++i) 
			cin >> a[i];
		ll sum = accumulate(a, a + n, 0);
		// cout << sum << " ";
		if(sum == 0)
			cout << "YES\n";
		else{
			if(sum < 0) cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}
