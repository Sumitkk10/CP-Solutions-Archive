#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--){
		ll n, ans = 0;
		cin >> n;
		for(i = 2; i <= n; i++){
			if(n%i == 0)
				ans++;
		}
		if(ans == 1)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}