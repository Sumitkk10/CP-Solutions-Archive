#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main()
{
	fast;
	ll t, i, j;
	cin >> t;
	while(t--){
		ll n, max = 0, max1 = 0;
		cin >> n;
		ll a[n], b[n], c[n];
		for(i = 0; i < n; i++)
			cin >> a[i];
		for(i = 0; i < n; i++)
			cin >> b[i];
		for(i = 0; i < n; i++)
			c[i] = a[i] * b[i];
		for(i = 0; i < n; i++){
			if(c[i] > max)
				max = c[i];
		}
		for(i = 0; i < n; i++){
			if(c[i] == max){
				if(b[i] > max1)
					max1 = b[i];
			}
		}
		for(i = 0; i < n; i++){
			if(c[i] == max && b[i] == max1){
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}
	
