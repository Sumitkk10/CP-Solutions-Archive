#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--){
		ll n, ans, rev = 0;
		cin >> n;
		ll a = n;
		while(n > 0){
			ans = n % 10;
			rev = (rev * 10) + ans;
			n = n/10;
		}
		if(a == rev) 
			cout << "wins" << '\n';
		else
			cout << "losses" << '\n'; 
		}
	return 0;
}