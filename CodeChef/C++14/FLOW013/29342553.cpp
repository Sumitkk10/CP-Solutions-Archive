#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a+b+c == 180)
			cout << "YES" <<'\n';

		else
			cout << "NO" << '\n';
	}
	return 0;
}