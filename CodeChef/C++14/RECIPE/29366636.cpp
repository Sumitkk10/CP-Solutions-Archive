#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

	int gcd(int a, int b) {
	ll temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ll t, i;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll z[n];
		for(i = 0; i < n; i++){
			cin >> z[i];
		}
		ll ans = z[0];
		for(i = 1; i < n; i++){
			ans = gcd(ans, z[i]);
		}
		for(i = 0; i < n; i++){
			cout << z[i]/ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}