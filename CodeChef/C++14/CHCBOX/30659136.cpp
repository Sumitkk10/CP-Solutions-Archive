#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, b = 0, max = 0, c = 0;
		cin >> n;
		ll a[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] >= max){
				max = a[i]; 
				b = i;
			}
		}
		for(ll i = 0; i < n; i++){
			if(a[i] == max){
				c = i;
				break;
			}
		}
		ll ans = (b - c) + 1;
		if(ans > n/2) cout << 0 << '\n';
		else if(ans <= n/2){
			cout << n/2 - ans + 1 << '\n';
		}
	}
	return 0;
}