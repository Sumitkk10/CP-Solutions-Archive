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
		ll n, m, k;
		cin >> n >> m >> k;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a+n);
		int i = n - 1;
		while((m * a[i]) > k)
			--i;
		cout << a[i] << "\n";
	}
	return 0;
}
