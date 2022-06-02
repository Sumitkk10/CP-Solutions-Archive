#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll ans = 0, a, k;
		cin >> a;
		while(a != 0){
			k = sqrt(a); 
			k = k * k;
			a = a - k;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}