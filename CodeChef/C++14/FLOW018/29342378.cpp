#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--){
		ll n, ans = 1;
		cin >> n;
		for(i = 1; i <= n; i++){
			ans *= i;
		}
		cout << ans << '\n';
	}
	return 0;
}