#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isPrime(int n){
	for(int i = 2; i <= sqrt(n); ++i)
		if(n % i == 0)
			return false;
	return true;
}

int main(){
	fast;
	ll a, b;
	cin >> a >> b;
	vector<ll> prime;
	for(int i = a; i <= b; ++i){
		if(isPrime(i))
			prime.push_back(i);
	}
	for(int i = 0; i < prime.size(); ++i){
		for(int j = i + 1; j < prime.size(); ++j){
			ll mul = prime[i] * prime[j];
			if(mul >= (a/ 2) * (b / 2) && mul <= (a * b))
				cout << prime[i] << "," << prime[j] << "\n";
		}
	}
	return 0;
}