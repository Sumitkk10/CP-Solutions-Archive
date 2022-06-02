#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll m, a, b;
		cin >> m >> a >> b;
		ll k = b - a;
		if(k % 3 != 0)
			cout << "Yes\n";
		else{
			if((k/3) <= m)
				cout << "No\n";
			else
				cout << "Yes\n";
		}
	}
	return 0;
}
