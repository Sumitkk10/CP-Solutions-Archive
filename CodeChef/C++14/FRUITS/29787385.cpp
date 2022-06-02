#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll n, m, k, ans;
		cin >> n >> m >> k;
		if(n==m)
			cout << 0 << '\n';
		else if(n > m){
			ans = n - m;
			if(ans <= k)
				cout << 0 << '\n';
			else if (ans > k)
				cout << n - (k + m) << '\n';
		}
		else if(n < m){
			ans = m - n;
			if(ans <= k)
				cout << 0 << '\n';
			else if (ans > k)
				cout << m - (k + n) << '\n';
		}
	}
	return 0;
}
	
