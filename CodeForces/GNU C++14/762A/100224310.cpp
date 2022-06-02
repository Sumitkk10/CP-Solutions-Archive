#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	vector<ll> fac;
	for(ll i = 1; i * i <= n; ++i){
		if(n % i == 0){
			fac.push_back(i);
			if(n/i != i)
				fac.push_back(n / i);
		}
	}
	sort(fac.begin(), fac.end());
	if(k > fac.size()){
		cout << "-1\n";
		return 0;
	}
	cout << fac[k - 1] << '\n';
	return 0;
}
