#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while(t--){
		ll n, i, even = 0, a, odd = 0;
		cin >> n;
		for(i = 0; i < n; i++){
			cin >> a;
			if(a % 2 == 0) even++;
			else odd++;
		}
		cout << odd * even << '\n';
	}
	return 0;
}
	
