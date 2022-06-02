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
		ll n, m, min = 1000000000001, a = 0;
		cin >> n >> m;
		ll f[n], p[n], ans = 0;
		for(i = 0; i < n; i++)
			cin >> f[i];
		for(i = 0; i < n; i++)
			cin >> p[i];
		for(i = 1; i <= m; i++){
			ans = 0; a = 0;
			for(j = 0; j < n; j++){
				if(i == f[j]){
					a++;
					ans += p[j];
				}
			}
			if(a!= 0){
				if(ans < min){
					min = ans;
				}
			}
		}
		cout << min << '\n';
	}
	return 0;
}
	
