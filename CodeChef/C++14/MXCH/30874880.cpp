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
		ll n, k;
		cin >> n >> k;
		ll a[n];
		a[0] = 1;
		for(int i = 1; i < n; ++i){
			a[i] = (i+1);
		}
		swap(a[k], a[n-1]);
		for(int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
} 