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
		ll n, k;
		cin >> n >> k;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		ll pre = k;
		for(int i = n - 1; i >= 0; --i){
			ll day = pre / a[i];
			day = day*a[i];
			pre = day;
		}
		cout << pre << "\n";
	}
	return 0;
}