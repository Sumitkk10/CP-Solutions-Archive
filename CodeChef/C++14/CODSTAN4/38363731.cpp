#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	ll t = 1;
	// cin >> t;
	while(t--){
		ll m, r;
		cin >> m >> r;
		cout << (r % m ? "No\n" : "Yes\n");
	}
	return 0;
}