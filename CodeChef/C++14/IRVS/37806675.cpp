#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isPrime(int n){ 
    if (n <= 1) return false; 
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; 
    return true; 
}

int main(){
	fast;
	ll t = 1;
	cin >> t;
	while(t--){
		ll n, sum = 0;
		cin >> n;
		for(int i = 2; i <= n; ++i)
			if(isPrime(i))
				sum += i;
		cout << sum%10 << "\n";
	}
	return 0;
}