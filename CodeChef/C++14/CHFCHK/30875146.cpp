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
		ll n;
		cin >> n;
		ll a[n], min = 100000000001;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] < min)
				min = a[i];
		}
		cout << min << '\n';
	}
	return 0;
} 