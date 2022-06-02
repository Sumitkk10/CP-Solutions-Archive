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
		ll a[n+1], anss = 0, div = 0, flag = 0;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i){
			if(i >= a[i]) continue;
			if(a[i] - i <= 2){
				anss += (a[i] - i)*1000; 
				div++;
			} 
			else{
				flag++;
				break;
			} 
		}
		if(!flag) cout << anss/div << "\n";
		else cout << "Too Much\n" ;
	}
	return 0;
}
