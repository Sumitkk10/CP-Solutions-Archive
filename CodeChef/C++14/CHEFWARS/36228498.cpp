#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll h, p;
		cin >> h >> p;
		while(h > 0 && p > 0){
			h -= p;
			if(h <= 0){ 
				cout << "1\n";
				break;
			}
			p /= 2;
			if(p <= 0){
				cout << "0\n";
				break;
			}
		}
	}
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}