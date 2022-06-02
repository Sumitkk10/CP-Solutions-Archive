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
		ll a[n], first = 0, second = 0;
		for(int i = 0; i < n; ++i) cin >> a[i];
			sort(a, a+n, greater<>());
		for(int i = 0; i < n; ++i){
			if(i == 1 || i == 2 || i % 2 == 0 && i != 0) second += a[i];
			else first += a[i]; 
		}
		if(first > second)cout << "first\n";
		else if(second > first) cout << "second\n";
		else cout << "draw\n";
	}
	return 0;
}
