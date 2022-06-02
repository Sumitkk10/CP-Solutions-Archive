#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll a, k, ans = 0;
		cin >> a;
		while(a!=0){
			k = a % 10;
			ans += k;
			a = a/10;
		}
		cout << ans << '\n';
	}
	return 0;
}