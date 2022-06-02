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
		ll a, ans = 0;
		cin >> a;
		while(a--){
			ll n, m;
			cin >> n >> m;
			if((m-n) > 5)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
	
