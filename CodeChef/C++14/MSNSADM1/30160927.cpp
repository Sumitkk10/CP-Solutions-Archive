#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
	fast;
	ll t, i;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n], b[n], max = 0;
		for(i = 0; i < n; i++){
			cin >> a[i];
		}
		for(i = 0; i < n; i++){
			cin >> b[i];
		}
		for(i = 0; i < n; i++){
			a[i] = a[i] * 20;
			b[i] = b[i] * 10;
			a[i] = a[i] - b[i];
			if(a[i] < 0) a[i] = 0;
		}
		for(i = 0; i < n; i++){
			if(a[i] > max)
				max = a[i];
		}
		cout << max << '\n';
	}
	return 0;
}
	
