// longest increasing subsequence 
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n], b[n], max = 0, max1 = 0;
		for(int i = 0; i < n; ++i){ 
			cin >> a[i];
			if(a[i] > max)
				max = a[i];
		}
		for(int i = 0; i < n; ++i){ 
			cin >> b[i];
			if(b[i] > max1)
				max1 = b[i];
		}
		if(max > max1 || max1 > max)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}
