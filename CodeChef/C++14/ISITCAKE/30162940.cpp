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
		ll a[10][10], ans = 0, j;
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				cin >> a[i][j];
			}
		}
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				if(a[i][j] <= 30) ans++;
			}
		}
		if(ans >= 60) cout <<"yes" << '\n';
		else cout <<  "no" << '\n';
	}
	return 0;
}
	
