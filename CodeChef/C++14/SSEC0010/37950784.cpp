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
		ll n;
		cin >> n;
		n %= 7;
		if(n == 1 || n == 0) cout << "83\n";
		else if(n == 2 || n == 6) cout << "83 83\n";
		else if(n == 3 || n == 5) cout << "83 83 69\n";
		else cout << "83 83 69 67\n";
	}
	return 0;
}