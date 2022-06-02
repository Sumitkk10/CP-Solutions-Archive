#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t, a;
	cin >> t;
	while(t--){
		cin >> a;
		if( a < 10)
			cout << "What an obedient servant you are!" << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}