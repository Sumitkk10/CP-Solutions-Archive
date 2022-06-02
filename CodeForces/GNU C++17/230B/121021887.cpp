#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool isPrime(long long x){
	for(long long i = 2; i*i <= x; ++i){
		if(x % i == 0) return false;
	}
	return true;
} 

void solve(){
	long long n;
	cin >> n;
	long double ok = sqrt(n);
	long long okk = sqrt(n);
	if(okk != ok or n == 1){
		cout << "NO\n";
		return;
	}
	if(isPrime(okk)) cout << "YES\n";
	else cout << "NO\n";
}
 
int main() {
	fast;
	int t = 1;
 	cin >> t;
	while(t--)
		solve();
	return 0;
}    