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
		n *= 2;
		ll k = n / 2, XOR = 0;
		if(k % 4 == 0) XOR = k;
		else if(k % 4 == 1) XOR = 1;
		else if(k % 4 == 2) XOR = k + 1;
		cout << 2 * XOR << "\n";
	}
	return 0;
}
