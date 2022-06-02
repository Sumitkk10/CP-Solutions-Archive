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
		int a, d, k, n, inc;
		cin >> a >> d >> k >> n >> inc;
		for(int i = 1; i <= n; ++i){
			if(i % k == 0) d += inc;
			a += d;
		}
		cout << a - d << "\n"; 
	}
	return 0;
}
