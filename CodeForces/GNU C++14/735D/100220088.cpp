#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isprime(ll x){
	if(x <= 3) return true;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)
			return false;
	return true;
}

void solve(){
	long long int n;
	cin >> n;
	if(isprime(n)){
		cout << "1\n";
		return;
	}
	if(isprime(n - 2) or (n & 1 ^ 1)){
		cout << "2\n";
		return;
	}
	cout << "3\n";
}

int main(){
	fast;
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}
