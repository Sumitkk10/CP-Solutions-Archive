#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--)
	{
		ld q, p, ans;
		cin >> q >> p;
		if(q < 1000){
			cout << fixed << setprecision(6) << q*p << '\n';
		}
		else if(q >= 1000){
			ans = p/10;
			p = p - ans;
			cout << fixed << setprecision(6) << q*p << '\n';
		}
	}
	return 0;
}