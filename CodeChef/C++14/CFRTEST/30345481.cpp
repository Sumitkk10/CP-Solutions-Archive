#include<bits/stdc++.h>

#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, cnt = 0;
		cin >> n;
		ll a[n], b[101];
		for(ll i = 0; i < n; i++)
			cin >> a[i];
		for(ll i = 0; i < 101; i++)
			b[i] = 0;
		for(ll i = 0; i < n; i++)
			b[a[i]]++;
		for(ll i = 0; i < 101; i++){
			if(b[i] >= 1) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}
	
