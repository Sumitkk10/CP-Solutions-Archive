#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n == 2015 || n == 2019 || n == 2017 || n == 2016 || n == 2010)
			cout << "HOSTED" << '\n';
		else
			cout << "NOT HOSTED" << '\n';
	}
	return 0;
}
	
