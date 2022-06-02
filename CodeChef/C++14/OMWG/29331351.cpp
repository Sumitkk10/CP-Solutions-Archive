#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll m, n, sol;
		cin >> m >> n;
		sol = m * (n-1) + n * (m-1);
		cout << sol << '\n';
	}
	return 0;
}