#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool isPrime(int x){
	for(int i = 2; i*i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 4; i <= n - 4; ++i){
		if(!isPrime(i) and !isPrime(n - i)){
			cout << i << ' ' << n - i << '\n';
			return;
		}
	}
}
 
int main() {
	fast;
	int t = 1;
 	// cin >> t;
	while(t--)
		solve();
	return 0;
}    