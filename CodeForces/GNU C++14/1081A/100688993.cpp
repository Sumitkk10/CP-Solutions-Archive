#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll highestpowerof2(ll n){ 
   ll p = (ll) log2(n); 
   return (ll) pow(2, p);  
}

void solve(){
	int n;
	cin >> n;
	cout << (n != 2 ? "1\n" : "2\n");
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
// 3 1 3
// 1 1 1 (Xor with 2)
//  