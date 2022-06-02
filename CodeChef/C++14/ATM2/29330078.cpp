#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		ll a[n], i;
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++){
			if(a[i] <= k){
				cout << 1;
				k = k - a[i];
			}
			else
				cout << 0;
		}
		cout <<'\n';
	}
	return 0;
}