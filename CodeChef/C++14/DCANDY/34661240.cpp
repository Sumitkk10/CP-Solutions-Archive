#include "bits/stdc++.h"
#define ll long long int
#define ld long double
using namespace std;

int main(){
	long long int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a+n, greater<>());
		ll sum = 0;
		for(int i = 2; i < n; i += 3)
			sum += a[i];
		cout << sum << '\n';
	}
	return 0;
}